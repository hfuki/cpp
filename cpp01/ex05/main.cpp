#include "Harl.hpp"

int	main()
{
	std::string cmd;
	Harl harl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Enter command(DEBUG, INFO, WARNING, ERROR): ";
		if (!std::getline(std::cin, cmd))
			return (1);
		harl.complain(cmd);
	}
	return (0);
}