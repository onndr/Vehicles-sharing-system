#include "Location.h"
#include "Components.h"
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

class Vehicle2 {
public:
    //attributes
    std::string id;
    std::string name;
    Location location;
    std::chrono::system_clock::time_point lastCheckup;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;
    bool needsCheckup;
    std::vector<Component2> components;


    //constructor & destructor
    Vehicle2() noexcept;
    ~Vehicle2() noexcept;
    Vehicle2(std::string name): name(name) {};
    Vehicle2(std::string vehicle_id,
            Location location,
            std::vector<Component2> components) noexcept;

    //getters
    std::string getId() const noexcept;
    std::string getName() const noexcept;
    Location getLocation() const noexcept;
    std::chrono::system_clock::time_point getLastCheckup() const noexcept;
    std::chrono::system_clock::time_point getStartTime() const noexcept;
    std::chrono::system_clock::time_point getEndTime() const noexcept;
    bool getNeedsCheckup() const noexcept;
    std::string getComponents() const noexcept;

    //setters
    void setId(std::string newId);
    void setName(std::string newName);
    void setLocation(Location newLocation);
    void setNeedsCheckup(bool isDamaged);
    void startTrip(std::chrono::system_clock::time_point start);
    void endTrip(std::chrono::system_clock::time_point stop);

    friend std::ostream& operator<<(std::ostream& output, Vehicle2 const& vehicle) noexcept;
    friend std::istream& operator>>(std::istream& input, Vehicle2& vehicle) noexcept;

};



