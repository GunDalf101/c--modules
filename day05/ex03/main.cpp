# include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	AForm *a;
	AForm *b;
	AForm *c;

	Intern Arnaldo;
	try{
		a = Arnaldo.makeForm("robotomy request", "Ebil");
		std::cout << std::endl;
		b = Arnaldo.makeForm("presidential pardon", "Ebil");
		std::cout << std::endl;
		c = Arnaldo.makeForm("shrubbery creation", "Ebil");
		std::cout << std::endl;

		Arnaldo.makeForm("foo", "Ebil");
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete a;
	delete b;
	delete c;
	return EXIT_SUCCESS;
}