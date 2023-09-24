#include "Harl.hpp"

void Harl::debug( void ){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "Fireball spellcasting initiated. Gathering elemental energies for an explosive incantation." << std::endl << std::endl;
}

void Harl::info( void ){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "Fireball spell successfully cast. Flames erupt in a fiery inferno, consuming all in its path." << std::endl << std::endl;
}

void Harl::warning( void ){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "Fireball spellcasting nearing critical heat levels. Extinguish or release with care to avoid collateral damage." << std::endl << std::endl;
}

void Harl::error( void ){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "Fireball spellcasting failed. Mana surge disrupted the incantation. Seek magical recovery immediately." << std::endl << std::endl;
}

void Harl::complain( std::string level ){
    logLev logPtr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string logs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; true; i++) {
        if (level == logs[i] || i > 4)
        {
            switch (i) {
                case 0:
                    (this->*logPtr[0])();
                    (this->*logPtr[1])();
                    (this->*logPtr[2])();
                    (this->*logPtr[3])();
                    break ;
                case 1:
                    (this->*logPtr[1])();
                    (this->*logPtr[2])();
                    (this->*logPtr[3])();
                    break ;
                case 2:
                    (this->*logPtr[2])();
                    (this->*logPtr[3])();
                    break ;
                case 3:
                    (this->*logPtr[3])();
                    break ;
                default:
                    std::cout << "Invalid Harl spell components" << std::endl;
                    break ;
            }
            return ;
        }
    }
}