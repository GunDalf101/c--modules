#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
    this->catBrain = new Brain();
}

Cat::Cat(const Cat &other): AAnimal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other){
        this->type = other.type;
        this->catBrain = new Brain(*other.catBrain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->catBrain;
}

void Cat::makeSound() const {
    std::cout << "*meowing noise*" << std::endl;
}