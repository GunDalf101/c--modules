#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class AForm;
# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat {
    private:
        std::string const	name;
        int					grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &copy);

        std::string const	&getName() const;
        int					getGrade() const;
        void				incrementGrade();
        void				decrementGrade();
        void				signForm(AForm &form);
        void                executeForm(AForm const &form);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);


#endif