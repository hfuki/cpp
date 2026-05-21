#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");

	a.attack("target");
	a.takeDamage(3);
	a.beRepaired(2);

	for (int i = 0; i < 11; ++i)
		a.attack("dummy");

	a.takeDamage(100);
	a.attack("after-dead");
	a.beRepaired(1);

	ClapTrap b(a);
	ClapTrap c;
	c = a;

	return 0;
}