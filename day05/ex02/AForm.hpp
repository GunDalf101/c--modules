#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"


class AForm {
    private:
        std::string const	_name;
        bool				isSigned;
        std::string const	_target;
        int const			_gradeToSign;
        int const			_gradeToExecute;
        AForm();
    public:
        AForm(std::string const &name, int gradeToSign, int gradeToExecute, std::string const &target);
        AForm(AForm const &copy);
        virtual ~AForm();

        AForm &operator=(AForm const &copy);

        std::string const	&getName() const;
        bool				getSigned() const;
        int					getGradeToSign() const;
        int					getGradeToExecute() const;
        std::string const	&getTarget() const;
        virtual void		executionOrder(Bureaucrat const &executor) const = 0;
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

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif