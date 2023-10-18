#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"


class Form {
    private:
        std::string const	_name;
        bool				isSigned;
        int const			_gradeToSign;
        int const			_gradeToExecute;
        Form();
    public:
        Form(std::string const &name, int gradeToSign, int gradeToExecute);
        Form(Form const &copy);
        ~Form();

        Form &operator=(Form const &copy);

        std::string const	&getName() const;
        bool				getSigned() const;
        int					getGradeToSign() const;
        int					getGradeToExecute() const;
        void				beSigned(Bureaucrat const &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif