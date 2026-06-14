#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name(""){}

Zombie::~Zombie()
{
        std::cout << name << " is destroyed" << std::endl;
}

void    Zombie::setName(std::string new_name)
{
        name = new_name;
}

void    Zombie::announce()
{
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
