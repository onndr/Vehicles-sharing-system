#include "Vehicle.h"
#include "Components.h"
#include <chrono>
int Vehicle::vcount;

bool Vehicle::isDamaged()
{
    for (auto c : components)
    {
        if (c->getIsDamaged())return true;
        //if (c.isBroken)return true;
    }
    return false;
}

std::chrono::system_clock::time_point Vehicle::startTrip()
{
    startTime = std::chrono::system_clock::now();
    return startTime;
}

std::chrono::system_clock::time_point Vehicle::endTrip()
{
    endTime = std::chrono::system_clock::now();
    return endTime;
}
