#include "Zombie.hpp"

void randomChump( std::string name ){
    Zombie newZombie;

    newZombie.nameIt(name);
    newZombie.announce();
}