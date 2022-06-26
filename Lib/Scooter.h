//
// Created by Helena on 04/05/2022.
//
#include "Vehicle.h"
#include "Components.h"

class Scooter: public Vehicle {
public:
    Scooter(std::string name): Vehicle(name) {}
    //setters
    void setFrontWheel(Wheel front);
    void setBackWheel(Wheel back);
    void setStand(Stand stand);
    void setBreaks(Breaks breaks);
    void setBattery(Battery battery);

    //getters
    Wheel getFrontWheel() const noexcept;
    Wheel getBackWheel() const noexcept;
    Stand getStand() const noexcept;
    Breaks getBreaks() const noexcept;
    Battery getBattery() const noexcept;

    //other
    float getBatteryLevel() const noexcept;
};