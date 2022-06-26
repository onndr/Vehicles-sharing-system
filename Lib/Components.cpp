//
// Created by Helena on 04/05/2022.
//

#include "Components.h"
#include <string>
using namespace std;

string Component2::sendErrorMessage() const noexcept {
    return "Component error message";
}

void Component2::setName(std::string name) {

}

void Component2::fixed() {

}

void Component2::broken() {

}

bool Component2::getStatus() {
    return false;
}
