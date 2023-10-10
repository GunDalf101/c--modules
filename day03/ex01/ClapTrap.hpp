#ifndef CLAPTRAP_CPP
# define CLAPTRAP_CPP

#include <iostream>

class ClapTrap {
    protected:
        std::string name;
        int HP;
        int EP;
        int damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif
