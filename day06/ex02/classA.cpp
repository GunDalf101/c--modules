#include "classA.hpp"

ClassA::ClassA() {
}

ClassA::ClassA(ClassA const &copy) {
    *this = copy;
}

ClassA::~ClassA() {
}

ClassA &ClassA::operator=(ClassA const &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}