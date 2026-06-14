#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal copy assignment operator called\n";
	if (this != &other)
		type = other.type;
	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called\n";
}

std::string AAnimal::getType(void) const
{
	return type;
}
