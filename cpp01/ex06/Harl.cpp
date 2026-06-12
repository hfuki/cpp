#include "Harl.hpp"

Harl::Harl(){}

void    Harl::complain(std::string level)
{
        void    (Harl::*f[])(void) =
        {
                &Harl::debug_comp,
                &Harl::info_comp,
                &Harl::warning_comp,
                &Harl::error_comp
        };

        std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        int i;
        for (i = 0; i < 4; i++)
        {
                if (level == levels[i])
                        break;
        }

        switch (i)
        {
                case 0:
                        (this->*f[0])();
                case 1:
                        (this->*f[1])();
                case 2:
                        (this->*f[2])();
                case 3:
                        (this->*f[3])();
                        break;
                default:
                        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
}

void	Harl::debug_comp()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-special ketchup burger."
			  <<" I really do!" << std::endl;
}

void	Harl::info_comp()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." 
			  << " You didn't put enough bacon in my burger! If you did,"
			  <<" I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning_comp()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
			  << " I've been coming for years, whereas you started "
			  << "working here just last month." << std::endl;
}

void	Harl::error_comp()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
