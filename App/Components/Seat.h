//
// Created by Helena on 04/05/2022.
//

#ifndef VETURILO_SEAT_H
#define VETURILO_SEAT_H
#include "../Components/Component.h"
#include <string>


class Seat: public Component {
private:
    using Component:: name;
    using Component:: broken;
public:
    std::string sendErrorMessage() const noexcept;
};


#endif //VETURILO_SEAT_H
