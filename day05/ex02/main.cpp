# include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Bureaucrat hermano("Hermano", 150);

	Bureaucrat ebil("Ebil", 1);
	std::cout << std::endl;

	std::cout << std::endl;
	ShrubberyCreationForm scf("Ebil");
	PresidentialPardonForm ppf("Ebil");
	RobotomyRequestForm rrf("Ebil");
	std::cout << std::endl;

	ebil.executeForm(scf);
	scf.beSigned(ebil);
	ebil.executeForm(scf);

	std::cout << std::endl;

	ebil.executeForm(ppf);
	ppf.beSigned(ebil);
	ebil.executeForm(ppf);

	std::cout << std::endl;

	ebil.executeForm(rrf);
	rrf.beSigned(ebil);
	ebil.executeForm(rrf);

	std::cout << std::endl;

	try {
		hermano.executeForm(scf);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	return EXIT_SUCCESS;
}