#pragma once
#include <vector>
#include "User.h"
#include "Currency.h"
#include "Location.h"
#include "Vehicle.h"


class PaymentSystem
{
public:
    PaymentSystem() {};
    Currency* countFee(Vehicle& v, double h);
    Payment* pay(Human* u, Vehicle& v, double h);
    Payment* pay(Human* u, Currency* c);
};


class Parking
{
private:
    std::vector<Vehicle*> vehicles;
    Location* location;
    PaymentSystem* psys;
    int id;
public:
    static int pcount;
    Parking() : id(pcount++), location(nullptr) { PaymentSystem psys; this->psys = &psys; };
    Parking(PaymentSystem& psys) : psys(&psys), id(pcount++), location(nullptr) {};
    int getId() { return id; }
    template<typename Selector>
    int getNumberOf(){
        int counter = 0;
        for (auto v : vehicles) {
            if (auto tp = static_cast<Selector*>(v))
                counter++;
        }
        return counter;
    };
    std::vector<Vehicle*> getAllVehicles() const { return this->vehicles; };
    std::vector<Vehicle*> getDamagedVehicles();
    void addVehicle(Vehicle* v) { this->vehicles.push_back(v); v->currentParking = this; };
    void removeVehicle(Vehicle* v) { 
        std::vector<Vehicle*>::iterator toErase;
        for (std::vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); i++)
        {
            if ((*i) == v) {
                toErase = i;
            }
        }
        vehicles.erase(toErase);
    };
    bool takeVehicle(Vehicle& v, Human& h);
    bool returnVehicle(Vehicle& v, Human& h);
    bool returnVehicle(Vehicle& v, Human& h, double hours);
    void reportDamagedVehicle(Vehicle& v, Component& c);
    friend std::ostream& operator<<(std::ostream& os, Parking& p) { os << p.toString(); return os; };
    friend std::istream& operator>>(std::istream& is, Parking& p);
    const std::string toString() {
        std::string tmp;
        tmp += std::to_string(id);
        tmp += ":";
        for (auto v : vehicles) {
            tmp += (*v).toString();
            tmp += ";";
        }
        return tmp;
    };
};


class System
{
private:
    std::vector<Parking*> parkings = std::vector<Parking*>();
    std::vector<Human*> humans = std::vector<Human*>();
    std::vector<Vehicle*> vehicles = std::vector<Vehicle*>();
    Currency income;
public:
    System(){};
    template <typename Selector>
    int getNumberOf() {
        int counter = 0;
        for (auto v : vehicles) {
            if (auto tp = static_cast<Selector*>(v))
                counter++;
        }
        return counter;
    };
    std::vector<Vehicle*>& getAllVehicles() { return vehicles; };
    std::vector<Vehicle*>& getDamagedVehicles();
    void addVehicle(Vehicle& v) { for (auto vp : vehicles) { if (vp == &v)return; }; vehicles.push_back(&v); };
    void addVehicle(Vehicle* v) { for (auto vp : vehicles) { if (vp == v)return; }; vehicles.push_back(v); };
    void addParking(Parking& p) { for (auto vp : parkings) { if (vp == &p)return; }; parkings.push_back(&p); };
    void addParking(Parking* p) { for (auto vp : parkings) { if (vp == p)return; };  parkings.push_back(p); };
};

