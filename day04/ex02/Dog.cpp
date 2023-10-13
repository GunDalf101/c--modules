#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
    this->dogBrain = new Brain();
}

Dog::Dog(const Dog &other): AAnimal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &other){
        this->type = other.type;
        this->dogBrain = new Brain(*other.dogBrain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->dogBrain;
}

void Dog::makeSound() const {
    std::cout << "*barking sound*" << std::endl;
}