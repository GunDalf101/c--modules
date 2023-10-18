# include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    Form form("Form", 49, 50);
    try {
        form.beSigned(Bureaucrat("Bureaucrat", 25));
        std::cout << form;
        form.beSigned(Bureaucrat("Bureaucrat", 50));
        std::cout << form;
        form.beSigned(Bureaucrat("Bureaucrat", 75));
        std::cout << form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    Bureaucrat bureaucrat("Bureaucrat", 75);
    bureaucrat.signForm(form);
}