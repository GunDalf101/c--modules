#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA {
private:
    Weapon& weapon;
    std::string name;

public:
    HumanA(std::string myName, Weapon& firstWeapon);

    void attack();
};


#endif