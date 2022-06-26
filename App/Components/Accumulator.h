//
// Created by Helena on 04/05/2022.
//

#ifndef VETURILO_ACCUMULATOR_H
#define VETURILO_ACCUMULATOR_H
#include "../Components/Component.h"
#include <string>

class Accumulator: public Component{
private:
    using Component:: name;
    using Component:: isBroken;
    float percentage;
public:
    std::string sendErrorMessage() const noexcept;
    //setters
    void charge(float addedPower);
    void use(float usedPower);
    //getters
    float getPercentage() const noexcept;
};


#endif //VETURILO_ACCUMULATOR_H
