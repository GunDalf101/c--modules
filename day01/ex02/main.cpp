#include <iostream>
#include <string>

int main(){
    std::string brainCell = "HI THIS IS BRAIN";
    std::string* brainPtr = &brainCell;
    std::string& brainRef = brainCell;

    std::cout << "Brain address  : " << &brainCell << std::endl;
    std::cout << "Brain pointer  : " << brainPtr << std::endl;
    std::cout << "Brain reference: " << &brainRef << std::endl;

    std::cout << "Brain value          : " << brainCell << std::endl;
    std::cout << "Brain pointer value  : " << *brainPtr << std::endl;
    std::cout << "Brain reference value: " << brainRef << std::endl;
}