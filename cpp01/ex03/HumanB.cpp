#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name) : name(name), weapon(NULL) {}

void    HumanB::attack()
{
        if (weapon)
                std::cout << name << " attacks with their " << weapon->getType() << std::endl;
        else
                std::cout << name << " has no weapon to attack with" << std::endl;
}

void	HumanB::setWeapon(Weapon* n_weapon)
{
	weapon = n_weapon;
}