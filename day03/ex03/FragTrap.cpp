# include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "Child FragTrap default constructor called" << std::endl;
    this->HP = 100;
    this->EP = 100;
    this->damage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "Child FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << this->name << " is asking for a high five!" << std::endl;
}