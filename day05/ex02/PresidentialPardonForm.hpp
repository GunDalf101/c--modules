#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

        void executionOrder(Bureaucrat const &executor) const;
};

#endif