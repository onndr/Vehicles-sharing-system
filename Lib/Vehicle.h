#pragma once
#include "Currency.h"
#include "Components.h"
#include "Location.h"
#include <iostream>
#include <string>
#include <chrono>
class Tariff
{
public:
	Currency* base;
	void setIntPart(int ip) { base->intPart = ip; };
	void setFractPart(int frp) { base->fractPart = frp; };
	Tariff(): base(nullptr) {};
	Tariff(Currency& base) : base(&base) {};
	Currency* getBase() { return this->base; };
	void setBase(Currency* c) { 
		this->base = c; 
		return;
	};
};

class Component
{
private:
	std::string name;
	bool isDamaged;
public:
	Component() : name("Component"), isDamaged(false) {};
	Component(std::string name) : name(name), isDamaged(false) {};
	bool getIsDamaged() { return this->isDamaged; };
	void setDamaged(bool isDamaged) { this->isDamaged = isDamaged; };
};

class Parking;

class Vehicle
{
private:
	int id;
	std::string name;
	Location* location;
	std::vector<Component*> components;
	std::chrono::system_clock::time_point startTime;
	std::chrono::system_clock::time_point endTime;
public:
	Parking* currentParking;
	Tariff* tariff;
	static int vcount;
	virtual ~Vehicle() {};
	Vehicle(const Vehicle& v) { id = v.id; name = v.name; tariff = v.tariff; components = v.components;}
	Vehicle() : id(vcount++), name(""), tariff(nullptr) {};
	Vehicle(std::string name) : id(vcount++), name(name), tariff(nullptr) {};
	Vehicle(std::string name, Tariff& t) : id(vcount++), name(name), tariff(&t) {};
	bool isDamaged();
	void addComponent(Component* c) { components.push_back(c); };
	std::vector<Component*> getComponents() { return components; };
	Tariff* getTariff() { return this->tariff; };
	void setTariff(Tariff* t) { this->tariff = tariff; }
	std::string getName() { return name; };
	int getId() { return id; };
	void setName(std::string name) { this->name = name; }
	bool operator==(Vehicle& v) { return this->id == v.id; };
	std::string toString() { 
		std::string tmp; 
		tmp += std::to_string(id); 
		tmp += ","; 
		tmp += name; 
		tmp += ",";  
		tmp += (*tariff->getBase()).toString(); 
		return tmp;
	};
	std::chrono::system_clock::time_point startTrip();
	std::chrono::system_clock::time_point getStartTime() { return startTime; }
	std::chrono::system_clock::time_point endTrip();
	std::chrono::system_clock::time_point getEndTime() { return endTime; }
	friend std::ostream& operator<<(std::ostream& os, Vehicle& v) { os << v.toString(); return os; };
	friend std::istream& operator>>(std::istream& is, Vehicle& v);
};
