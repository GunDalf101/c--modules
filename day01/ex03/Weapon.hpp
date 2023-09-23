#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(std::string newType);
    const std::string& getType();

    void setType(const std::string& newType);
};


#endif