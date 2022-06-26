//
// Created by Helena on 04/05/2022.
//

#ifndef INC_209_X_ROWERY_MIEJSKIE_COMPONENTS_H
#define INC_209_X_ROWERY_MIEJSKIE_COMPONENTS_H

#include "Components.h"
#include <string>

// w domysle sendErrorMessage bedzie wyswietlac w ostreamie ze wszytsko git, chyba ze cos bedzie nie tak..

class Component2 {
public:
    //attributes
    std::string name;
    bool isBroken;


    virtual std::string sendErrorMessage() const noexcept;
    //setters
    void setName(std::string name);
    void fixed();
    void broken();

    //getter
    bool getStatus();
};


class Accumulator: public Component2{
private:
    float percentage;
public:
    std::string sendErrorMessage() const noexcept;
    //setters
    void charge(float addedPower);
    void use(float usedPower);
    //getters
    float getPercentage() const noexcept;
};


class Pedals: public Component2 {
public:
    std::string sendErrorMessage() const noexcept;
};


class Stand: public Component2 {
public:
    std::string sendErrorMessage() const noexcept;
};


class Breaks: public Component2 {
public:
    std::string sendErrorMessage() const noexcept;
};


class Battery: public Component2 {
private:
    float percentage;
public:
    std::string sendErrorMessage() const noexcept;
    //setters
    void charge(float addedPower);
    void use(float usedPower);
    //getters
    float getPercentage() const noexcept;
};


class Seat: public Component2 {
public:
    std::string sendErrorMessage() const noexcept;
};


class Tank: public Component2 {
private:
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


class Wheel: public Component2 {
public:
    std::string sendErrorMessage() const noexcept;
};



#endif //INC_209_X_ROWERY_MIEJSKIE_COMPONENTS_H

