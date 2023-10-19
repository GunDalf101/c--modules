#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

        void executionOrder(Bureaucrat const &executor) const;
};

#endif