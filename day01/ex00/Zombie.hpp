#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
    private:
        std::string name;
    public:

        ~Zombie();

        void announce (void);
        void nameIt( std::string name );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif