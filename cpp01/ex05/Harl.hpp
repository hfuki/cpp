#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
	void	debug_comp();
	void	info_comp();
	void	warning_comp();
	void	error_comp();

public:
	Harl();

	void	complain(std::string level);
};

#endif