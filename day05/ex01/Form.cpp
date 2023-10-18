# include "Form.hpp"

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(Form const &copy) : _name(copy._name), isSigned(copy.isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
    *this = copy;
}

Form::~Form() {
}

Form &Form::operator=(Form const &copy) {
    if (this != &copy) {
        (std::string)this->_name = (std::string)copy._name;
        this->isSigned = copy.isSigned;
    }
    return *this;
}

std::string const &Form::getName() const {
    return this->_name;
}

bool Form::getSigned() const {
    return this->isSigned;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw Form::GradeTooLowException();
    }
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
    out << "Form " << form.getName() << " is " << (form.getSigned() ? "" : "not ") << "signed, grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
} 