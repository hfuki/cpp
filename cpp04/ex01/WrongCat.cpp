#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongMeow!\n";
}