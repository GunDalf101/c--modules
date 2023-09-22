#include "PhoneBook.hpp"
#include <_ctype.h>
#include <cctype> 

void    PhoneBook::addContact(){
    Contact newContact;
    std::string input;

    std::cout << "First name: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
        return ;
    newContact.setFirstName(input);
    std::cout << "Last name: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
        return ;
    newContact.setLastName(input);
    std::cout << "Nickname: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
        return ;
    newContact.setNickName(input);
    std::cout << "Phone number: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
        return ;
    newContact.setPhoneNumber(input);
    std::cout << "Darkest secret: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
        return ;
    newContact.setDarkestSecret(input);

    if (this->size == 8)
        this->size = 0;
    this->contacts[this->size] = newContact;
    this->size++;
}

void printWithWidth(const std::string& str, int width) {
    if (str.length() > width)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << str;
    for (int i = str.length(); i < width; ++i) {
        std::cout << ' ';
    }
}

void    PhoneBook::searchContact(){
    std::string header1 = "Index";
    std::string header2 = "FirstName";
    std::string header3 = "LastName";
    std::string header4 = "Nickname";
    std::string ind;
    int columnWidth = 10;

    
    printWithWidth(header1, columnWidth);
    std::cout << '|';
    printWithWidth(header2, columnWidth);
    std::cout << '|';
    printWithWidth(header3, columnWidth);
    std::cout << '|';
    printWithWidth(header4, columnWidth);
    std::cout << '|' << std::endl;

    
    for (int i = 0; i < columnWidth * 4 + 3; ++i) {
        std::cout << '-';
    }
    std::cout << std::endl;

    for (int i = 0; i < 8; i++){
        std::cout << i << ".";
        printWithWidth("", columnWidth - 2);
        std::cout << '|';
        printWithWidth(this->contacts[i].getFirstName(), columnWidth);
        std::cout << '|';
        printWithWidth(this->contacts[i].getLastName(), columnWidth);
        std::cout << '|';
        printWithWidth(this->contacts[i].getNickName(), columnWidth);
        std::cout << '|' << std::endl;
    }
    for (int i = 0; i < columnWidth * 4 + 3; ++i) {
        std::cout << '-';
    }
    std::cout << std::endl;

    std::cout << "Give an Index: ";
    if (std::getline(std::cin, ind) == false)
        exit(0);
    int index = std::atoi(ind.c_str());
    if (index > 7 || index < 0 || std::isdigit(*ind.c_str()) == false)
        std::cout << "The given indexex is out of range!!" << std::endl;
    else {
        std::cout << "First name     : " << this->contacts[index].getFirstName() << std::endl;
        std::cout << "Last name      : " << this->contacts[index].getLastName() << std::endl;
        std::cout << "Nickname       : " << this->contacts[index].getNickName() << std::endl;
        std::cout << "Phone number   : " << this->contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret : " << this->contacts[index].getDarkestSecret() << std::endl;
    }    
}

