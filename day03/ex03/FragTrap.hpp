#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
    private:
        FragTrap(void);
    public:
        FragTrap(std::string name);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif