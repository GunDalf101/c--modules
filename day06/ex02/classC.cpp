#include "classC.hpp"

ClassC::ClassC() {
}

ClassC::ClassC(ClassC const &copy) {
    *this = copy;
}

ClassC::~ClassC() {
}

ClassC &ClassC::operator=(ClassC const &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}
