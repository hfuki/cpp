#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}