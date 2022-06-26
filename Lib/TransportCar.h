//
// Created by Helena on 04/05/2022.
//
#include "Components.h"
#include "Parking.h"


class TransportCar: public Vehicle {
private:
    Parking currentParking;
public:
    //setters
    void setCurrentParking(Parking newParking);
    //components setters
    void setTank(Tank tank);
    void setFrontRightWheel(Wheel frontRight);
    void setFrontLeftWheel(Wheel frontLeft);
    void setBackRightWheel(Wheel backRight);
    void setBackLeftWheel(Wheel backLeft);
    void setBreaks(Breaks breaks);
    void setAccumulator(Accumulator acc);

    //getters
    Parking getCurrentParking() const noexcept;
    //components getters
    Tank getTank() const noexcept;
    Wheel getFrontRightWheel() const noexcept;
    Wheel getFrontLeftWheel() const noexcept;
    Wheel getBackRightWheel() const noexcept;
    Wheel getBackLeftWheel() const noexcept;
    Breaks getBreaks() const noexcept;
    Accumulator getAccumulator() const noexcept;
};
