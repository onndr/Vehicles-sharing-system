#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"
#include "Currency.h"


class Human {
public:
    static int hcount;
    int id;
    int age;
    double weight;
    double height;
    std::string name;
    std::string email;
    std::string phoneNumber;
    Vehicle* currVehicle;

    virtual ~Human(){};
    Human() : id(hcount++), age(0), weight(0), height(0), 
        name(""), email(""), phoneNumber(""), currVehicle(nullptr) {};
    Human(std::string name) : id(hcount++), age(0), weight(0), height(0),
        name(name), email(""), phoneNumber(""), currVehicle(nullptr) {};
    Human(int id, int age, double weight, double height, 
        std::string name, std::string email, std::string phoneNumber) 
        : id(id), age(age), weight(weight), height(height), currVehicle(nullptr),
        name(name), email(email), phoneNumber(phoneNumber) {};
    Vehicle* getCurrentVehicle() { return currVehicle; };
    const int getId() { return id; };
    void setId(int id) { this->id = id;};
    void setVehicle(Vehicle*);
    const std::string getName() { return name; };
    void setName(std::string name) { this->name = name; };
    friend std::ostream& operator<<(std::ostream& os, Human& h) { os << h.toString(); return os; };
    friend std::istream& operator>>(std::istream& is, Human& h);
    const std::string toString() { 
        std::string tmp; 
        tmp += std::to_string(id); 
        tmp += ","; 
        tmp += name;
        if (currVehicle) {
            tmp += ",";
            tmp += currVehicle->toString();
        }
        return tmp; 
    };
};

class User : public Human {
public:
    bool isActive;
    User() : isActive(true) {};
    virtual ~User(){};
    void resetVehicle();
    void setIsActive(bool isActive) { this->isActive = isActive; };
};

class AdultUser : public User {
public:
    static int count;
    Wallet* wallet;
    ~AdultUser() { if (wallet)delete wallet; };
    AdultUser() :wallet(new Wallet(id)) { count++; };
    AdultUser(std::string name) : AdultUser() { setName(name); };
    std::vector<Payment*> getPayments();
    virtual bool pay(Currency&);
    bool topUp(Currency&);
    Currency* getBalance() { return wallet->getBalance(); };
    Wallet* getWallet() { return wallet; };
    friend std::ostream& operator<<(std::ostream& os, AdultUser& u);
    friend std::istream& operator>>(std::istream& is, AdultUser& u);
    const std::string toString();
};

class DependantUser : public User {
public:
    AdultUser* dependOnUser;
};

class KidUser : public DependantUser {
public:
    AdultUser* sponsor;
};

class DisabledUser : public DependantUser {
public:
    AdultUser* caregiver;
    std::FILE disabilityConfirmation;
};


class StaffMember : public Human {
    static const int rightsLvl = 1;
    Currency salary;
    std::string task;
public:
    Wallet* wallet;
    ~StaffMember() { if (wallet)delete wallet; };
    StaffMember() :wallet(new Wallet(id)) {};
    StaffMember(std::string n) :wallet(new Wallet(id)), Human(n) {};
    void setTask(std::string task);
};

class Worker : public StaffMember {
public:
    static int count;
    Worker(std::string name) { setName(name); count++; };
    std::string toString() {
        std::string string;
        string += std::to_string(id);
        string += ',';
        string += name;
        string += ',';
        string += wallet->toString();
        return string;
    }
    friend std::ostream& operator<<(std::ostream& os, Worker& w) { return os << w.toString(); };
    bool repairVehicle(Vehicle* v);
};

class Admin : public StaffMember {
public:
    bool addVehicle(Vehicle* v);
    //bool addParking(Parking* p);
};

class Manager : public Admin {
public:
    void assignTask(std::string task, StaffMember& s);
};
