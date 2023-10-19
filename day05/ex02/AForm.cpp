# include "AForm.hpp"

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute, std::string const &target) : _name(name), isSigned(false), _target(target), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(AForm const &copy) : _name(copy._name), isSigned(copy.isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
    *this = copy;
}

AForm::~AForm() {
}

AForm &AForm::operator=(AForm const &copy) {
    if (this != &copy) {
        (std::string)this->_name = (std::string)copy._name;
        this->isSigned = copy.isSigned;
    }
    return *this;
}

std::string const &AForm::getName() const {
    return this->_name;
}

std::string const &AForm::getTarget() const {
    return this->_target;
}

bool AForm::getSigned() const {
    return this->isSigned;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
    out << "Form " << form.getName() << " is " << (form.getSigned() ? "" : "not ") << "signed, grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
} 