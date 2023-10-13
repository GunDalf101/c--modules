#include "Character.hpp"

Character::Character() : name("default") {
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(std::string const &name) : name(name) {
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character &other) : name(other.name) {
    *this = other;
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        this->name = other.name;
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] != NULL) {
                delete this->inventory[i];
            }
            if (other.inventory[i] != NULL) {
                this->inventory[i] = other.inventory[i]->clone();
            } else {
                this->inventory[i] = NULL;
            }
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL) {
            delete this->inventory[i];
        }
    }
}

std::string const &Character::getName() const {
    return this->name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
        this->inventory[idx]->use(target);
    }
}
