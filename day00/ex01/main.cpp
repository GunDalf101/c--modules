#include "PhoneBook.hpp"

int main(){
    PhoneBook phoneBook;
    std::string input;

    while(1){
        std::cout << "> ";
        if (std::getline(std::cin, input) == false)
            exit(0);
        if (input == "EXIT")
            exit(0);
        else if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContact();
        else
            std::cout << "This Is Not a Command!!" << std::endl;
    }
}