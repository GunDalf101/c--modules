#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::setWeapon(Weapon& newWeapon){
    this->weapon = &newWeapon;
}

HumanB::HumanB(std::string myName): weapon(NULL){
    this->name = myName;
}

void HumanB::attack(){
    if (this->weapon != NULL)
        std::cout<< this->name << " attacks with their " << this->weapon->getType() << std::endl;
}