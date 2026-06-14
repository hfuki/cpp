#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	type = "Dog";
	std::cout << "Dog default constructor called\n";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called\n";
	brain = new Brain();
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;

		// deep copy
		if (brain == 0)
			brain = new Brain();
		*brain = *(other.brain);
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
	delete brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!\n";
}

Brain* Dog::getBrain(void) const
{
	return brain;
}
