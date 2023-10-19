#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy) {
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {
    AForm::operator=(copy);
    return *this;
}

void PresidentialPardonForm::executionOrder(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    } else if (!this->getSigned()) {
        std::cout << "Error: form not signed" << std::endl;
    }
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}