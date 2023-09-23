#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
#include <sys/_types/_size_t.h>

class PhoneBook{
    private:
        Contact contacts[8];
        size_t  size;
        size_t  count;
    public:
        PhoneBook(){
            size = 0;
            count = 0;
        }

        void    theAddition();
        void    theSearch();
};


#endif