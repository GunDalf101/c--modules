# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name){
    std::cout << "Grand-Child DiamondTrap default constructor called" << std::endl;
    this->name = name;
    this->HP = FragTrap::HP;
    this->EP = ScavTrap::EP;
    this->damage = FragTrap::damage;
}


DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy.name + "_clap_name"), FragTrap(copy.name), ScavTrap(copy.name) {
    std::cout << "Grand-Child DiamondTrap copy constructor called" << std::endl;
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
    std::cout << "Grand-Child DiamondTrap assignation operator called" << std::endl;
    if (this != &copy) {
        this->name = copy.name;
        this->HP = copy.HP;
        this->EP = copy.EP;
        this->damage = copy.damage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Grand-Child DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}