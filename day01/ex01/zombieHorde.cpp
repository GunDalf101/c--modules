# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    Zombie* myZombieHorde = new Zombie[N];

    for (int i = 0;i < N; i++){
        myZombieHorde[i].nameIt(name);
    }
    return myZombieHorde;
}