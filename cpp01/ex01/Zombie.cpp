#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name(""){}

void	Zombie::set(const std::string& new_name)
{
	name = new_name;
}

void	Zombie::announce()
{
	std::cout << name << std::endl;
}