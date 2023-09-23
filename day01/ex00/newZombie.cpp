#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
    Zombie* newZombie = new Zombie;

    newZombie->nameIt(name);
    return newZombie;
}