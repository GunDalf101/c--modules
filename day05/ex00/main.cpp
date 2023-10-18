# include "Bureaucrat.hpp"

int main(){
    Bureaucrat bureaucrat("Bureaucrat", 1);
    std::cout << bureaucrat;
    try {
        bureaucrat.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << bureaucrat;
    try {
        bureaucrat.incrementGrade();
        bureaucrat.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bur("Bureaucrat", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}