#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int	main()
{
	Weapon bat;
	Weapon hammer;
	HumanA A("A", bat);
	HumanB B("B");

	bat.setType("vulnerable bat");
	hammer.setType("tough hammer");

	A.attack();

	B.setWeapon(&hammer);
	B.attack();

	std::cout << std::endl;

	bat.setType("touch bat");
	hammer.setType("vulnerable hammer");

	A.attack();
	B.attack();

	return (0);
}
