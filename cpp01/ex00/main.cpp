#include "Zombie.hpp"

int main()
{
	std::cout << "make heap zombie" << std::endl;
	Zombie* zombie = newZombie("heap");
	zombie->announce();
	delete(zombie);
	std::cout << "make stack zombie" << std::endl;
	randomChump("stack");
	return 0;
}
