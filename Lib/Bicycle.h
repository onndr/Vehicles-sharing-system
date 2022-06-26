//
// Created by Helena on 04/05/2022.
//

#include "Vehicle.h"
#include "Parking.h"
#include "Components.h"
#include <string>
#include <vector>


class Bicycle: public Vehicle {
private:
    Parking currentParking;

public:
    Bicycle() : Vehicle() {};
    Bicycle(std::string name): Vehicle(name) {};
    //setters
    void setCurrentParking(Parking newParking);
    //components setters
    void setFrontWheel(Wheel front);
    void setBackWheel(Wheel back);
    void setPedals(Pedals pedals);
    void setSeat(Seat seat);
    void setStand(Stand stand);
    void setBreaks(Breaks breaks);
    void setBattery(Battery battery);

    //getters
    Parking getCurrentParking() const noexcept;
    //components getters
    Wheel getFrontWheel() const noexcept;
    Wheel getBackWheel() const noexcept;
    Stand getStand() const noexcept;
    Breaks getBreaks() const noexcept;
    Battery getBattery() const noexcept;

    //other
    float getBatteryLevel() const noexcept;
};
