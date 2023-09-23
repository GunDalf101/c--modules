#include "Zombie.hpp"

int main(){
    randomChump("BrainDead");
    Zombie* mainZom = newZombie("Lich");
    mainZom->announce();
    delete mainZom;
}