#include "Harl.hpp"

bool isInputValid(const std::string& input)
{
	if (input != "DEBUG" && input != "INFO"
	&& input != "WARNING" && input != "ERROR")
	{
		std::cout << "Invalid Harl spell components" << std::endl;
		return false;
	}
	return true;
}

int main(void)
{
	Harl harl;
	std::string input;

	while (1)
	{
		std::cout << "Enter a level for Harl spellcasting: ";
		getline(std::cin, input);
		if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
			std::cout << std::endl;
        }
        if (input == "EXIT")
            exit(0);
		if (input.empty() || !isInputValid(input))
			continue;
		harl.complain(input);
	}
	return 0;
}