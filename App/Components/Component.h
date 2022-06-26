//
// Created by Helena on 04/05/2022.
//

#ifndef VETURILO_COMPONENT_H
#define VETURILO_COMPONENT_H
#include "../Components/Component.h"
#include <string>


class Component {
protected:
    std:: string name;
    bool isBroken;
public:
    string sendErrorMessage() const noexcept;
    //setters
    void setName(std::string name);
    void fixed();
    void broken();
    //getter
    bool getStatus();
};


#endif //VETURILO_COMPONENT_H
