#include "Harl.hpp"

Harl::Harl(){}

void	Harl::complain(std::string level)
{
	void	(Harl::*f[])(void) =
	{
		&Harl::debug_comp,
		&Harl::info_comp,
		&Harl::warning_comp,
		&Harl::error_comp
	};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*f[i])();
			return;
		}
	}
}

void	Harl::debug_comp()
{
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-special ketchup burger."
			  <<" I really do!" << std::endl;
}

void	Harl::info_comp()
{
	std::cout << "I cannot believe adding extra bacon costs more money." 
			  << " You didn't put enough bacon in my burger! If you did,"
			  <<" I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning_comp()
{
	std::cout << "I think I deserve to have some extra bacon for free."
			  << " I've been coming for years, whereas you started "
			  << "working here just last month." << std::endl;
}

void	Harl::error_comp()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
