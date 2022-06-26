//
// Created by Helena on 04/05/2022.
//

#ifndef VETURILO_BREAKS_H
#define VETURILO_BREAKS_H
#include "../Components/Component.h"
#include <string>


class Breaks: public Component {
private:
    using Component:: name;
    using Component:: broken;
public:
    std::string sendErrorMessage() const noexcept;
};


#endif //VETURILO_BREAKS_H
