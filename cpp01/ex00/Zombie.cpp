#include "Zombie.hpp"

Zombie::Zombie() : name("") {};

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set(const std::string& new_n)
{
	name = new_n;
}
