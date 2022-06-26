//
// Created by Helena on 04/05/2022.
//

#ifndef VETURILO_STAND_H
#define VETURILO_STAND_H
#include "../Components/Component.h"
#include <string>


class Stand: public Component {
private:
    using Component:: name;
    using Component:: broken;
public:
    std::string sendErrorMessage() const noexcept;
};


#endif //VETURILO_STAND_H
