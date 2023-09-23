#include "Zombie.hpp"

int main(){
    int zombieNum = 2;

    Zombie* mainZoms = zombieHorde(zombieNum, "Death Knight");
    for (int i = 0;i < zombieNum; i++){
        mainZoms[i].announce();
    }
    delete[] mainZoms;
}