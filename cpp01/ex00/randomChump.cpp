#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie new_z;

	new_z.set(name);
	new_z.announce();
}