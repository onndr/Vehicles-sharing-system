//
// Created by Helena on 04/05/2022.
//

#ifndef VETURILO_WHEEL_H
#define VETURILO_WHEEL_H
#include "../Components/Component.h"
#include <string>


class Wheel: public Component {
private:
    using Component:: name;
    using Component:: broken;
public:
    std::string sendErrorMessage() const noexcept;
};


#endif //VETURILO_WHEEL_H
