#include "Zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(5, "zom");
	print_hordename(5, zombies);
	delete[] zombies;
}
