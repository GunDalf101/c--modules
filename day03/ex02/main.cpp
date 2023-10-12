#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(){
    FragTrap fragtrap("Killer");
    FragTrap fragtrap2("Victim");

    std::cout << std::endl;

    fragtrap.attack("Victim");
    fragtrap2.takeDamage(11);

    std::cout << std::endl;

    fragtrap2.attack("Killer");
    fragtrap2.beRepaired(5);

    std::cout << std::endl;

    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);
    fragtrap.beRepaired(5);

    std::cout << std::endl;

    fragtrap.highFivesGuys();
    fragtrap2.highFivesGuys();

    std::cout << std::endl;

    return 0;
}