#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    FragTrap scavtrap("Killer");
    FragTrap scavtrap2("Victim");

    std::cout << std::endl;

    scavtrap.attack("Victim");
    scavtrap2.takeDamage(11);

    std::cout << std::endl;

    scavtrap2.attack("Killer");
    scavtrap2.beRepaired(5);

    std::cout << std::endl;

    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);
    scavtrap.beRepaired(5);

    std::cout << std::endl;

    scavtrap.highFivesGuys();
    scavtrap2.highFivesGuys();

    std::cout << std::endl;

    return 0;
}