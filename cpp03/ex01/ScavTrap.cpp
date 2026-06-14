#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :ClapTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
        std::cout << "ScavTrap copy assignment operator called\n";
        if (this != &other)
        {
                ClapTrap::operator=(other);
        }
        return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called\n";
}


void ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack (no hit points)\n";
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack (no energy)\n";
		return;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}
