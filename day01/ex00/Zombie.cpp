# include "Zombie.hpp"

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(): name("Undead"){

}

Zombie::~Zombie(){
    std::cout << this->name << " is exorcised!" << std::endl;
}

void Zombie::nameIt( std::string name ){
    this->name = name;
}