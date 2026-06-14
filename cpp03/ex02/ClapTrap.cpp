#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called\n";
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't attack (no hit points)\n";
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't attack (no energy)";
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " already has 0 hit points\n";
		return ;
	}
	if (hitPoints <= amount)
		hitPoints = 0;
	else
		hitPoints -= amount;

	std::cout << "ClapTrap " << name << " takes " << amount
		<< " damage, hit points now " << hitPoints << "\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't repair (no hit points)\n";
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't repair (no energy)\n";
		return ;
	}
	energyPoints--;
	hitPoints += amount;

	std::cout << "ClapTrap " << name << " repairs itself for " << amount
		<< ", hit points now " << hitPoints << "\n";
}
