#include "iter.hpp"

int main() {
    int intArr[5] = {1, 2, 3, 4, 5};
    std::string strArr[5] = {"one", "two", "three", "four", "five"};
    float floatArr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "intArr: ";
    iter(intArr, 5, print);
    std::cout << std::endl;
    std::cout << "strArr: ";
    iter(strArr, 5, print);
    std::cout << std::endl;
    std::cout << "floatArr: ";
    iter(floatArr, 5, print);
    std::cout << std::endl;
    return 0;
}