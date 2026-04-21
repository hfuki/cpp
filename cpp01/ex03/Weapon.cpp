#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

const std::string& Weapon::getType() 
{
	return (type);
}

void	Weapon::setType(const std::string& n_type)
{
	type = n_type;
}
