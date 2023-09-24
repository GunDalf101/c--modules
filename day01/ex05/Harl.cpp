#include "Harl.hpp"

void Harl::debug( void ){
    std::cout << "Fireball spellcasting initiated. Gathering elemental energies for an explosive incantation." << std::endl;
}

void Harl::info( void ){
    std::cout << "Fireball spell successfully cast. Flames erupt in a fiery inferno, consuming all in its path." << std::endl;
}

void Harl::warning( void ){
    std::cout << "Fireball spellcasting nearing critical heat levels. Extinguish or release with care to avoid collateral damage." << std::endl;
}

void Harl::error( void ){
    std::cout << "Fireball spellcasting failed. Mana surge disrupted the incantation. Seek magical recovery immediately." << std::endl;
}

void Harl::complain( std::string level ){
    logLev logPtr[4] = {&Harl::debug, &Harl::info, &Harl::error, &Harl::warning};
    std::string logs[4] = {"DEBUG", "INFO", "ERROR", "WARNING"};

    for (int i = 0; i < 4; i++) {
        if (level == logs[i])
            (this->*logPtr[i])();
    }
}