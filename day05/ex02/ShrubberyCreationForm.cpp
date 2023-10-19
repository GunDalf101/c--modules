#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137, target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy) {
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
    AForm::operator=(copy);
    return *this;
}

void ShrubberyCreationForm::executionOrder(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    } else if (!this->getSigned()) {
        std::cout << "Error: form not signed" << std::endl;
    }
    std::ofstream file;
    std::string filename = this->getTarget() + "_shrubbery";
    file.open(filename.c_str());
    if (file.is_open()) {
        file << "       _-_" << std::endl;
        file << "    /~~   ~~\\" << std::endl;
        file << " /~~         ~~\\" << std::endl;
        file << "{               }" << std::endl;
        file << " \\  _-     -_  /" << std::endl;
        file << "   ~  \\\\ //  ~" << std::endl;
        file << "_- -   | | _- _" << std::endl;
        file << "  _ -  | |   -_" << std::endl;
        file << "      // \\\\" << std::endl;
        file.close();
    } else {
        std::cout << "Error: could not open file" << std::endl;
    }
}