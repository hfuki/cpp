#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
        std::cout << "------ClapTrap------\n";
        ClapTrap c("C");
        c.attack("target");

        std::cout << "\n------ScavTrap------\n";
        ScavTrap s("S");
        s.takeDamage(30);
        s.beRepaired(10);
        s.guardGate();

        std::cout << "\n------FragTrap------\n";
        FragTrap f("F");
        f.attack("enemy");
        f.takeDamage(50);
        f.beRepaired(20);
        f.highFivesGuys();

        std::cout <<"\n------Copy test------\n";
        FragTrap f2(f);
        FragTrap f3;
        f3 = f;

        return 0;
}
