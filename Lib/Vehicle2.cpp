#include "Vehicle2.h"
#include "Location.h"
#include <vector>
#include <string>
#include <chrono>
using namespace std;

Vehicle2::Vehicle2() noexcept{
    // mozna jeszcze dac zmienna ktoa by trzymala w sobie wszytskie do tej pory uzyte id
    // w wektorze zeby sprawdzic czy sie nie powtarzaja(?)

    //vehicle_id = "00000";
    components = {};
    needsCheckup = false;
    chrono::system_clock::time_point now = std::chrono::system_clock::now();
    lastCheckup = std::chrono::system_clock::now();
}

Vehicle2::Vehicle2(string id, Location loc, vector<Component2> com) noexcept{
    //vehicle_id = id;
    components = com;
    location = loc;
    needsCheckup = false;
    time_t now = time(0);
    //lastCheckup = ctime(&now);
}

//string Vehicle2::checkForDamage() const noexcept {
//    return string();
//}

Location Vehicle2::getLocation() const noexcept {
    return Location();
}

bool Vehicle2::getNeedsCheckup() const noexcept {
    return false;
}

void Vehicle2::setNeedsCheckup(bool isDamaged) {

}

void Vehicle2::startTrip(std::chrono::system_clock::time_point start) {

}

void Vehicle2::endTrip(std::chrono::system_clock::time_point end) {

}

void Vehicle2::setLocation(Location newLocation) {

}
