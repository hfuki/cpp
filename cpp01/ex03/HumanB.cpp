#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name) : name(name), weapon(NULL) {}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon* n_weapon)
{
	weapon = n_weapon;
}