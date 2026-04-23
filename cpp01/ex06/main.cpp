#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string cmd;
	Harl harl;

	if (ac != 2)
		return (0);
	cmd = av[1];
	harl.complain(cmd);
	return (0);
}