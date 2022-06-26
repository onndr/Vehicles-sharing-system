//
// Created by Helena on 04/05/2022.
//

#ifndef VETURILO_TANK_H
#define VETURILO_TANK_H
#include "../Components/Component.h"
#include <string>


class Tank: public Component {
private:
    using Component:: name;
    using Component:: broken;
    float gasCurrent;
    float capacity;
public:
    std::string sendErrorMessage() const noexcept;
    //setters
    void fillTank(float addedGas);
    void use(float usedGas);
    //getters
    float getGasCurrent() const noexcept;
    float getCapacity() const noexcept;
};


#endif //VETURILO_TANK_H
