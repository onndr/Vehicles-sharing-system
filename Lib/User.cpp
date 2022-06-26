#include "pch.h"
#include "User.h"
#include "Vehicle.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Currency.h"
int Human::hcount = 0;
int AdultUser::count = 0;
int Worker::count = 0;

bool AdultUser::pay(Currency& curr)
{
    return wallet->pay(&curr);
}

bool AdultUser::topUp(Currency& curr)
{
    return wallet->topUp(&curr);
}

std::vector<Payment*> AdultUser::getPayments() {
    return wallet->getPayments();
}

void Human::setVehicle(Vehicle* v) {
    this->currVehicle = v;
}

void User::resetVehicle() {
    this->currVehicle = nullptr;
}

const std::string AdultUser::toString() {
    std::string string;
    string += std::to_string(id);
    string += ',';
    string += name;
    string += ',';
    string += wallet->toString();
    return string;
}

std::ostream& operator<<(std::ostream& os, AdultUser& u){
    return os << u.toString();
}

std::istream& operator>>(std::istream& is, AdultUser& u) {
    std::string str, tmp;
    is >> str;
    int comas = 0;
    int id = 0;
    std::string name;
    for (int i = 0; i < str.length(); i++)
    {   
        if (str[i] == ',') {
            switch (comas) {
                case 0: id = std::stoi(tmp); tmp = ""; break;
                case 1: name = tmp; tmp = ""; break;
                default: tmp += str[i];
            }
            comas++;
            continue;
        }
        tmp += str[i];
    }
    std::stringstream ss(tmp);
    ss >> *u.wallet;
    u.setId(id);
    u.setName(name);
    return is;
}

std::istream& operator>>(std::istream& is, Human& h) {
    int id;
    std::string tmp;
    std::string in;
    is >> in;
    for (auto c : in) {
        if (c == ',') {
            id = std::stoi(tmp);
            tmp = "";
        }
        else {
            tmp += c;
        }
    }
    h.setId(id);
    h.setName(tmp);
    return is;
}

