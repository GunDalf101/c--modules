#include "ClapTrap.hpp"

int main(){
    ClapTrap claptrap("Killer");
    ClapTrap claptrap2("Victim");

    std::cout << std::endl;

    claptrap.attack("Victim");
    claptrap2.takeDamage(11);

    std::cout << std::endl;

    claptrap2.attack("Killer");
    claptrap2.beRepaired(5);

    std::cout << std::endl;

    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);
    claptrap.beRepaired(5);

    std::cout << std::endl;

    return 0;
}