#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac != 2){
		std::cout << "Way too many parameters!!" << std::endl;
		exit(0);
	}
	std::string input = av[1];
	harl.complain(input);
	return 0;
}