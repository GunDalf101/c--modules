#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"


class Intern {
    private:
    public:
        Intern();
        Intern(Intern const &copy);
        ~Intern();

        Intern &operator=(Intern const &copy);

        AForm *makeForm(std::string const &name, std::string const &target);

        class FormNotFoundException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif