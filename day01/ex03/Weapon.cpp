#include "Weapon.hpp"

const std::string& Weapon::getType() {
    return this->type;
}

void Weapon::setType(const std::string& newType) {
    this->type = newType;
}

Weapon::Weapon(std::string newType){
    this->type = newType;
}