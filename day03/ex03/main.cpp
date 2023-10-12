#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

int main(){
    DiamondTrap diamondtrap("Killer");
    DiamondTrap diamondtrap2("Victim");

    std::cout << std::endl;

    diamondtrap.attack("Victim");
    diamondtrap2.takeDamage(50);

    std::cout << std::endl;

    diamondtrap2.attack("Killer");
    diamondtrap2.takeDamage(50);
    diamondtrap2.beRepaired(5);

    std::cout << std::endl;

    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(5);
    diamondtrap.beRepaired(80);

    std::cout << std::endl;

    diamondtrap.highFivesGuys();
    diamondtrap2.highFivesGuys();

    std::cout << std::endl;

    diamondtrap.guardGate();
    diamondtrap2.guardGate();

    std::cout << std::endl;

    diamondtrap.whoAmI();
    diamondtrap2.whoAmI();

    std::cout << std::endl;

    return 0;
}