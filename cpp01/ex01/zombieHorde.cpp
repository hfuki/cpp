#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
        Zombie *zombies = new Zombie[N];

        for (int i = 0; i < N; i++)
                zombies[i].setName(name);
        return (zombies);
}

void	print_hordename(int N, Zombie* zombies)
{
	for (int i = 0; i < N; i++)
	{
		std::cout << i << std::endl;
		zombies[i].announce();
	}
}