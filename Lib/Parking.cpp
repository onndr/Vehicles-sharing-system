#include "Parking.h"
#include "Vehicle.h"
#include <iostream>

int Parking::pcount;
std::vector<Vehicle*> Parking::getDamagedVehicles()
{
    std::vector<Vehicle*> tmp;
    for (std::vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); i++) {
        if ((*i)->isDamaged())
        {
            tmp.push_back(*i);
        }
    }
    return tmp;
}

bool Parking::takeVehicle(Vehicle& v, Human& h)
{
    bool isContained = false;
    for (Vehicle* i : vehicles) {
        if (&v == i) isContained = true;
    }
    if (isContained) {
        h.setVehicle(&v);
        v.currentParking = nullptr;
        v.startTrip();
        std::vector<Vehicle*>::iterator toErase;
        for (std::vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); i++)
        {
            if ((**i) == v) {
                toErase = i;
            }
        }
        vehicles.erase(toErase);
    }
    return isContained;
}

Currency* PaymentSystem::countFee(Vehicle& v, double h) {
    Currency* t = v.getTariff()->getBase();
    Currency* toPay = new Currency((*t * h));
    return toPay;
}

Payment* PaymentSystem::pay(Human* u, Currency* toPay)
{
    if (auto adult = dynamic_cast<AdultUser*>(u)) {
        if (adult->pay(*toPay)) {
            Payment p = Payment(0, toPay, "Info here");;
            adult->wallet->addPayment(&p);
            return &p;
        }
    }
    else if (auto kid = dynamic_cast<KidUser*>(u)) {
        return pay(kid->dependOnUser, toPay);
    }
    else if (auto dis = dynamic_cast<DisabledUser*>(u)) {
        Currency c;
        return pay(dis->dependOnUser, &c);
    }
    return nullptr;
}

Payment* PaymentSystem::pay(Human* u, Vehicle& v, double h)
{
    Currency* toPay = countFee(v, h);
    return pay(u, toPay);
}

bool Parking::returnVehicle(Vehicle& v, Human& h)
{
    std::chrono::system_clock::time_point start = v.getStartTime();
    std::chrono::system_clock::time_point end = v.endTrip();
    try {
        auto u = static_cast<User&>(h);
        h.currVehicle = nullptr;
        v.currentParking = this;
        std::chrono::system_clock::duration dur = end - start;
        auto m = std::chrono::duration_cast<std::chrono::minutes>(end - start);
        double hours = (double)m.count() / 60;
        psys->pay(&h, v, hours);
    }
    catch(std::bad_cast& c) {
        std::cout << c.what();
    }
    addVehicle(&v);
    return true;
}

bool Parking::returnVehicle(Vehicle& v, Human& h, double hours)
{
    try {
        auto u = static_cast<User&>(h);
        h.currVehicle = nullptr;
        v.currentParking = this;
        psys->pay(&h, v, hours);
    }
    catch (std::bad_cast& c) {
        std::cout << c.what();
    }
    addVehicle(&v);
    return true;
}

void Parking::reportDamagedVehicle(Vehicle& v, Component& c)
{
    for (auto vp : getAllVehicles()) {
        if (vp == &v) {
            c.setDamaged(true);
            return;
        }
    }
}

std::vector<Vehicle*>& System::getDamagedVehicles() {
    std::vector<Vehicle*> tmp;
    for (std::vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); i++) {
        if ((*i)->isDamaged())
        {
            tmp.push_back(*i);
        }
    }
    return tmp;
}