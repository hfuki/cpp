#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called\n";
	*this = other;
}

FragTrap&       FragTrap::operator=(const FragTrap& other)
{
        std::cout << "FragTrap copy assignment operator called\n";
        if (this != &other)
        {
                ClapTrap::operator=(other);
        }
        return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a high five!\n";
}
