#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
	std::string name;

	public:
	Zombie();

	void	set(const std::string& name);
	void	announce();
};

Zombie *zombieHorde(int N, std::string name);
void	print_hordename(int N, Zombie* zombies);

#endif