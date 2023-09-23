#include "PhoneBook.hpp"
#include <_ctype.h>
#include <cctype> 
#include <ios>

void    PhoneBook::theAddition(){
    Contact newContact;
    std::string input;

    std::cout << "First name: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
    {
        std::cout << "Can't leave an empty Field!!" << std::endl;
        return ;
    }
    newContact.setFirstName(input);
    std::cout << "Last name: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
    {
        std::cout << "Can't leave an empty Field!!" << std::endl;
        return ;
    }
    newContact.setLastName(input);
    std::cout << "Nickname: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
    {
        std::cout << "Can't leave an empty Field!!" << std::endl;
        return ;
    }
    newContact.setNickName(input);
    std::cout << "Phone number: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
    {
        std::cout << "Can't leave an empty Field!!" << std::endl;
        return ;
    }
    newContact.setPhoneNumber(input);
    std::cout << "Darkest secret: ";
    if (std::getline(std::cin, input) == false)
        exit(0);
    if (input == "")
    {
        std::cout << "Can't leave an empty Field!!" << std::endl;
        return ;
    }
    newContact.setDarkestSecret(input);

    if (this->size == 8)
        this->size = 0;
    if (this->count >= 8)
        this->count = 8;
    this->contacts[this->size] = newContact;
    std::cout << "!!Contact Saved Succefully!!" << std::endl;
    this->size++;
    this->count++;
}

void formatPrint(const std::string& str, int width) {
    if (str.length() > width)
        std::cout << std::right << std::setw(width) << str.substr(0, 9) + ".";
    else
        std::cout << std::right << std::setw(width) << str;
}

void    PhoneBook::theSearch(){
    std::string ind;
    int columnWidth = 10;

    if (this->count == 0){
        std::cout << "The Contact Table is Empty!!" << std::endl;
        return ;
    }
    formatPrint("Index", columnWidth);
    std::cout << std::right << '|';
    formatPrint("FirstName", columnWidth);
    std::cout << std::right << '|';
    formatPrint("LastName", columnWidth);
    std::cout << std::right << '|';
    formatPrint("Nickname", columnWidth);
    std::cout << std::right << '|' << std::endl;

    
    for (int i = 0; i < columnWidth * 4 + 3; ++i) {
        std::cout << std::right << '-';
    }
    std::cout << std::right << std::endl;

    for (int i = 0; i < this->count; i++){
        formatPrint("", columnWidth - 2);
        std::cout << std::right << i << ".";
        std::cout << std::right << '|';
        formatPrint(this->contacts[i].getFirstName(), columnWidth);
        std::cout << std::right << '|';
        formatPrint(this->contacts[i].getLastName(), columnWidth);
        std::cout << std::right << '|';
        formatPrint(this->contacts[i].getNickName(), columnWidth);
        std::cout << std::right << '|' << std::endl;
    }
    for (int i = 0; i < columnWidth * 4 + 3; ++i) {
        std::cout << std::right << '-';
    }
    std::cout << std::right << std::endl;

    std::cout << "Give an Index: ";
    if (std::getline(std::cin, ind) == false)
        exit(0);
    int index = std::atoi(ind.c_str());
    if (index > this->count - 1 || index < 0 || std::isdigit(*ind.c_str()) == false)
        std::cout << "The given index is out of range!!" << std::endl;
    else {
        std::cout << "First name     : " << this->contacts[index].getFirstName() << std::endl;
        std::cout << "Last name      : " << this->contacts[index].getLastName() << std::endl;
        std::cout << "Nickname       : " << this->contacts[index].getNickName() << std::endl;
        std::cout << "Phone number   : " << this->contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret : " << this->contacts[index].getDarkestSecret() << std::endl;
    }    
}

