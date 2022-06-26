//
// Created by Helena on 24/05/2022.
//

#include "Location.h"
#include "Parking.h"
#include <vector>
using namespace std;

Location::Location() noexcept{

}
Location::Location(float x, float y) noexcept{

}

//getters
double Location::getX() const noexcept{
    return -1;
}
double Location::getY() const noexcept{
    return -1;
}
vector<double> Location::getLocation() const noexcept{
    return std::vector<double>{-1., -1.};
}

//setters
void Location::setX(){

}

void Location::setY(){

}

void Location::setLocation(Location newLocation){

}

//other
//bool Location::isParking(vector<Parking> parkingList){
//    return false;
//}
//Parking Location::findClosestParking(vector<Parking> parkingList){
//    return Parking();
//}