#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << std::endl;
std::cout << meta->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();
std::cout << std::endl;
delete meta;
delete j;
delete i;
std::cout << std::endl;

const WrongAnimal* wrongMeta = new WrongAnimal();
const WrongAnimal* wrongJ = new WrongCat();
const WrongCat* wrongI = new WrongCat();
std::cout << std::endl;
std::cout << wrongMeta->getType() << " " << std::endl;
std::cout << wrongJ->getType() << " " << std::endl;
std::cout << wrongI->getType() << " " << std::endl;
std::cout << std::endl;
wrongJ->makeSound();
wrongI->makeSound();
wrongMeta->makeSound();
std::cout << std::endl;
delete wrongMeta;
delete wrongJ;
return 0;
}