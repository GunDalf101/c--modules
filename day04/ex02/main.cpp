#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

#define MAX_ANIMALS 4

int main()
{
	const AAnimal* Hound = new Dog();
	std::cout << std::endl;

	const AAnimal* pussyCat = new Cat();
	std::cout << std::endl;

	std::cout << "[ ANIMALS ]" << std::endl;
	const AAnimal* animals[MAX_ANIMALS];

	std::cout << "[ DOGS ]" << std::endl;
	for (size_t i = 0; i < MAX_ANIMALS / 2; i++) {
		animals[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << "[ CATS ]" << std::endl;
	for (size_t i = MAX_ANIMALS / 2; i < MAX_ANIMALS; i++) {
		animals[i] = new Cat();
		std::cout << std::endl;
	}
    std::cout << "[ MAKE SOUNDS ]" << std::endl;
    for (size_t i = 0; i < MAX_ANIMALS; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
    std::cout << std::endl;
	std::cout << "[ DELETE ANIMALS ]" << std::endl;
	for (size_t i = 0; i < MAX_ANIMALS; i++) {
		delete animals[i];
	}
	std::cout << "[ ANIMALS DELETED ]" << std::endl;
	std::cout << std::endl;
    delete Hound;
    delete pussyCat;
	return 0; 
}