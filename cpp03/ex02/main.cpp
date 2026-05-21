#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "------ClapTrap------\n";
	ClapTrap c("C");
	c.attack("target");

	std::cout << "------ScavTrap------\n";
	ScavTrap s("S");
	s.takeDamage(30);
	s.beRepaired(10);
	s.guardGate();

	std::cout <<"------Copy test------\n";
	ScavTrap s2(s);
	ScavTrap s3;
	s3 = s;

	return 0;
}