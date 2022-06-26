// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "..\Lib\User.h"
#include "..\Lib\Parking.h"
#include "..\Lib\Bicycle.h"
#include "..\Lib\Vehicle.h"
#include "..\Lib\Scooter.h"
#include <Windows.h>
#include <time.h>

using namespace std;

void showMenu() {
    std::cout << "Choose from options below:" << std::endl;
    std::cout << "0: Show all parkings" << std::endl;
    std::cout << "1: Show specific parking" << std::endl;
    std::cout << "2: Show number of parkings" << std::endl;
    std::cout << "3: Add parking" << std::endl;
    
    std::cout << std::endl;

    std::cout << "4: Show all vehicles" << std::endl;
    std::cout << "5: Show specific vehicle" << std::endl;
    std::cout << "6: Show number of vehicles" << std::endl;
    std::cout << "7: Add vehicle" << std::endl;
    std::cout << "8: Put vehicle to parking" << std::endl;

    std::cout << std::endl;

    std::cout << "9: Show all people" << std::endl;
    std::cout << "10: Show number of people" << std::endl;

    std::cout << std::endl;

    std::cout << "11: Add adult user" << std::endl;
    std::cout << "12: Show all adult users" << std::endl;
    std::cout << "13: Show number of adult users" << std::endl;
    std::cout << "14: Show specific adult user" << std::endl;

    std::cout << std::endl;
    
    std::cout << "15: Add worker" << std::endl;
    std::cout << "16: Show all workers" << std::endl;
    std::cout << "17: Show number of workers" << std::endl;
    std::cout << "18: Show specific worker" << std::endl;

    std::cout << std::endl;

    std::cout << "100: Take vehicle" << std::endl;
    std::cout << "101: Return vehicle" << std::endl;
    std::cout << "69: Exit" << std::endl;
} 

bool isNumber(const string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int takeOption() {
    std::string option;
    std::cout << "Enter your option > ";
    std::cin >> option;

    if (isNumber(option)) return std::stoi(option);
    else throw std::invalid_argument("Error: Invalid option");
}

int main()
{
    int option = -1;
    std::vector<Parking*> parkings;
    std::vector<Vehicle*> vehicles;
    std::vector<Human*> people;
    std::vector<AdultUser*> users;
    std::vector<Worker*> workers;
    do {
        try {
            AdultUser* currUser = nullptr;
            Parking* parking = nullptr;
            Worker* worker = nullptr;
            Tariff* tariff = nullptr;
            Vehicle* vehicle = nullptr;
            Currency* currency = nullptr;

            showMenu();
            option = takeOption();
            std::string tmp = "";
            int itmp = 0;
            switch (option) {
            case 0:
                for (auto p : parkings) {
                    std::cout << *p << std::endl;
                }
                break;
            case 1:
                std::cout << "Enter parking's id > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                for (auto p : parkings) {
                    if (p->getId() == itmp) std::cout << *p << std::endl;
                }
                break;
            case 2:
                std::cout << Parking::pcount << std::endl;
                break;
            case 3:
                parking = new Parking();
                parkings.push_back(parking);
                break;
            case 4:
                for (auto v : vehicles) {
                    std::cout << *v << std::endl;
                }
                break;
            case 5:
                std::cout << "Enter vehicle's id > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                for (auto v : vehicles) {
                    if (v->getId() == itmp) std::cout << *v << std::endl;
                }
                break;
            case 6:
                std::cout << Vehicle::vcount << std::endl;
                break;
            case 7:
                currency = new Currency();
                vehicle = new Vehicle();
                tariff = new Tariff();

                std::cout << "Enter vehicle's name > ";
                std::cin >> tmp;
                vehicle->setName(tmp);
                std::cout << std::endl << "Enter int part of cost per hour > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                else { throw new std::invalid_argument("Invalid parameter"); };
                currency->intPart = itmp;
                std::cout << std::endl << "Enter fract part of cost per hour > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                else { throw new std::invalid_argument("Invalid parameter"); };
                currency->fractPart = itmp;

                tariff->base = currency;
                vehicle->tariff = tariff;

                vehicles.push_back(vehicle);

                break;
            case 8:
                std::cout << std::endl << "Enter vehicle's id > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                for (auto v : vehicles) {
                    if (v->getId() == itmp) {
                        std::cout << std::endl << "Enter parking's id > ";
                        std::cin >> tmp;
                        if (isNumber(tmp)) {
                            itmp = std::stoi(tmp);
                        }

                        if (v->currentParking != nullptr) {
                            v->currentParking->removeVehicle(v);
                        }

                        for (auto p : parkings) {
                            if (p->getId() == itmp) {
                                for (auto vp : p->getAllVehicles()) {
                                    if (v == vp) break;
                                }
                                p->addVehicle(v); 
                            }
                        }
                        break;
                    }
                }
                break;
            case 9:
                for (auto h : people) {
                    std::cout << *h << std::endl;
                }
                break;
            case 10:
                std::cout << Human::hcount << std::endl;
                break;
            case 11:
                std::cout << "Enter user's name > ";
                std::cin >> tmp;
                currUser = new AdultUser(tmp);
                currUser->wallet->balance = new Currency();
                people.push_back(currUser);
                users.push_back(currUser);
                break;
            case 12:
                for (auto au : users) {
                    std::cout << *au << std::endl;
                }
                break;
            case 13:
                std::cout << AdultUser::count << std::endl;
                break;
            case 14:
                std::cout << "Enter user's id > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                for (auto au : users) {
                    if (au->getId() == itmp) std::cout << *au << std::endl;
                }
                break;
            case 15:
                std::cout << "Enter worker's name > ";
                std::cin >> tmp;
                worker = new Worker(tmp);
                worker->wallet->balance = new Currency();
                people.push_back(worker);
                workers.push_back(worker);
                break;
            case 16:
                for (auto w : workers) {
                    std::cout << *w << std::endl;
                }
                break;
            case 17:
                std::cout << Worker::count << std::endl;
                break;
            case 18:
                std::cout << "Enter worker's id > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                for (auto w : workers) {
                    if (w->getId() == itmp) std::cout << *w << std::endl;
                }
                break;
            case 69:
                break;
            case 100:
                std::cout << "Enter person's id > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                for (auto p : people) {
                    if (p->getId() == itmp) {
                        std::cout << "Enter vehicle's id > ";
                        std::cin >> tmp;
                        if (isNumber(tmp)) {
                            itmp = std::stoi(tmp);
                        }
                        for (auto v : vehicles) {
                            if (v->getId() == itmp) {
                                if (v->currentParking) {
                                    v->currentParking->takeVehicle(*v, *p);
                                    break;
                                }
                                else {
                                    std::cout << std::endl << "Vehicle with this id: " << itmp << " is not on parking" << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            case 101:
                std::cout << "Enter person's id > ";
                std::cin >> tmp;
                if (isNumber(tmp)) {
                    itmp = std::stoi(tmp);
                }
                for (auto p : people) {
                    if (p->getId() == itmp) {
                        if (p->currVehicle) {
                            std::cout << "Enter parking's id > ";
                            std::cin >> tmp;
                            if (isNumber(tmp)) {
                                itmp = std::stoi(tmp);
                                for (auto par : parkings) {
                                    if (par->getId() == itmp) {
                                        std::cout << "Enter for how many hours the vehicle was rented> ";
                                        std::cin >> tmp;
                                        if (isNumber(tmp)) {
                                            par->returnVehicle(*p->currVehicle, *p, std::stof(tmp));
                                        }
                                    }
                                }
                            }
                        }
                        else {
                            std::cout << std::endl << "Person with id: " << itmp << " doesn't rent vehicle now" << std::endl;
                            break;
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
        catch (const std::invalid_argument& e) {
            std::cout << std::endl;
            std::cout << e.what() << std::endl;
            std::cout << std::endl;
        }
    } while (option != 69);

    for (auto p : parkings) {
        delete p;
    }

    for (auto p : vehicles) {
        delete p;
    }

    for (auto p : people) {
        delete p;
    }
}