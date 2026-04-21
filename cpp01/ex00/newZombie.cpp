#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* new_z = new Zombie();

	new_z->set(name);
	return (new_z);
}