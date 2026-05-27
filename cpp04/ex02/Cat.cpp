#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	type = "Cat";
	std::cout << "Cat default constructor called\n";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called\n";
	brain = new Brain();
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;

		if (brain == 0)
			brain = new Brain();
		*brain = *(other.brain);
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}

Brain* Cat::getBrain(void) const
{
	return brain;
}