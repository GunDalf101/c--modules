#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"
#include "Base.hpp"
#include <iostream>

Base *generate(void) {
    int random = rand() % 3;
    std::cout << random << std::endl;
    if (random == 0) {
        std::cout << "A" << std::endl;
        return new ClassA();
    }
    else if (random == 1) {
        std::cout << "B" << std::endl;
        return new ClassB();
    }
    else {
        std::cout << "C" << std::endl;
        return new ClassC();
    }
}

void identify(Base *p) {
    if (dynamic_cast<ClassA *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<ClassB *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<ClassC *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p) {
    if (dynamic_cast<ClassA *>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<ClassB *>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<ClassC *>(&p))
        std::cout << "C" << std::endl;
}

int main() {
    srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}

