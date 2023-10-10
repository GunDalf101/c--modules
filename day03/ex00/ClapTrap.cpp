# include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), HP(10), EP(10), damage(0) {
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "ClapTrap assignation operator called" << std::endl;
    this->name = copy.name;
    this->HP = copy.HP;
    this->EP = copy.EP;
    this->damage = copy.damage;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (this->HP > 0 && this->EP > 0){
        this->EP -= 1;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
    }
    else if (this->HP <= 0)
        std::cout << "ClapTrap " << this->name << " what's dead can't Attack!" << std::endl;
    else if (this->EP <= 0)
        std::cout << "ClapTrap " << this->name << " is out of Energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->HP == 0 || this->HP - amount <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has already been destroyed!" << std::endl;
        this->HP = 0;
        return ;
    }
    this->HP -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->HP > 0 && this->EP > 0)
    {
        this->HP += amount;
        this->EP -= 1;
        std::cout << "ClapTrap " << this->name << " is repairing for " << amount << " HP!" << std::endl;
    }
    else if (this->HP <= 0)
        std::cout << "ClapTrap " << this->name << " can't Repair what's already dead!" << std::endl;
    else if (this->EP <= 0)
        std::cout << "ClapTrap " << this->name << " is out of Energy!" << std::endl; 
}