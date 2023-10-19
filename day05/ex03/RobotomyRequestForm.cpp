#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy) {
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
    AForm::operator=(copy);
    return *this;
}

void RobotomyRequestForm::executionOrder(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    } else if (!this->getSigned()) {
        std::cout << "Error: form not signed" << std::endl;
    }
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2) {
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "Robotomization of " << this->getTarget() << " failed" << std::endl;
    }
}