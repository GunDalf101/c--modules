#include "Intern.hpp"
#include "AForm.hpp"
#include <string>

Intern::Intern() {
}

Intern::Intern(Intern const &copy) {
    *this = copy;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &copy) {
    if (this != &copy) {
    }
    return *this;
}

AForm *newRobotomyRequestForm(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm *newPresidentialPardonForm(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm *newShrubberyCreationForm(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

typedef AForm *(*formCreate)(std::string const &target);

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
    AForm *form;
    std::string const names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    formCreate formCreate[3] = {&newRobotomyRequestForm, &newPresidentialPardonForm, &newShrubberyCreationForm};

    for (int i = 0; i < 3; i++) {
        if (name == names[i]) {
            form = formCreate[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    throw Intern::FormNotFoundException();
    return NULL;
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}