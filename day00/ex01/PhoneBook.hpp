#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        size_t  size;
    public:
        PhoneBook(){
            size = 0;
        }

        void    addContact();
        void    searchContact();
};


#endif