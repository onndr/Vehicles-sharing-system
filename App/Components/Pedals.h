//
// Created by Helena on 04/05/2022.
//

#ifndef VETURILO_PEDALS_H
#define VETURILO_PEDALS_H
#include "../Components/Component.h"
#include <string>


class Pedals: public Component {
private:
    using Component:: name;
    using Component:: broken;
public:
    std::string sendErrorMessage() const noexcept;
};


#endif //VETURILO_PEDALS_H
