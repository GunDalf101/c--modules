#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materiaCount(0) {
    for (int i = 0; i < 4; i++) {
        this->_materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        this->_materiaCount = other._materiaCount;
        for (int i = 0; i < 4; i++) {
            if (this->_materias[i] != NULL) {
                delete this->_materias[i];
            }
            if (other._materias[i] != NULL) {
                this->_materias[i] = other._materias[i]->clone();
            } else {
                this->_materias[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i] != NULL) {
            delete this->_materias[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (this->_materiaCount < 4) {
        this->_materias[this->_materiaCount] = m;
        this->_materiaCount++;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i] != NULL && this->_materias[i]->getType() == type) {
            return this->_materias[i]->clone();
        }
    }
    return NULL;
}