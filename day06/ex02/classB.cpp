#include "classB.hpp"

ClassB::ClassB() {
}

ClassB::ClassB(ClassB const &copy) {
    *this = copy;
}

ClassB::~ClassB() {
}

ClassB &ClassB::operator=(ClassB const &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}