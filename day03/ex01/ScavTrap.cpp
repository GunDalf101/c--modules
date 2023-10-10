# include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    std::cout << "Child ScavTrap default constructor called" << std::endl;
    this->HP = 100;
    this->EP = 50;
    this->damage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "Child ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (this->HP > 0 && this->EP > 0){
        this->EP -= 1;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
    }
    else if (this->HP <= 0)
        std::cout << "ScavTrap " << this->name << " what's dead can't Attack!" << std::endl;
    else if (this->EP <= 0)
        std::cout << "ScavTrap " << this->name << " is out of Energy!" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode!" << std::endl;
}