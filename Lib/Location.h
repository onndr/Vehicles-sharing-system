//
// Created by Helena on 24/05/2022.
//
#pragma once
//#include "Parking.h"
#include <iostream>
#include <string>
#include <vector>


class Location {
private:
    float x_coord;
    float y_coord;
public:
    Location() noexcept;
    Location(float x, float y) noexcept;

    //getters
    double getX() const noexcept;
    double getY() const noexcept;
    std::vector<double> getLocation() const noexcept;

    //setters
    void setX();
    void setY();
    void setLocation(Location newLocation);

    //other
    /*bool isParking(std::vector<Parking> parkingList);
    Parking findClosestParking(std::vector<Parking> parkingList);*/

    friend std::ostream& operator<<(std::ostream& output, Location const& location) noexcept;
    friend std::istream& operator>>(std::istream& input, Location& location) noexcept;
};


