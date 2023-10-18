# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name) {
    *this = copy;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy) {
    if (this != &copy) {
        (std::string)this->name = (std::string)copy.name;
        this->grade = copy.grade;
    }
    return *this;
}

std::string const &Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::incrementGrade() {
    if (this->grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << *this << " signs " << form << std::endl;
    } catch (std::exception &e) {
        std::cout << *this << " cannot sign " << form << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}