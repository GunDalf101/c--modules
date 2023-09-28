#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>

HumanA::HumanA(std::string myName, Weapon& firstWeapon) : weapon(firstWeapon){
    this->name = myName;
    this->weapon = firstWeapon;
}

void HumanA::attack(){
    std::cout<< this->name << " attacks with their " << this->weapon.getType() << std::endl;
}