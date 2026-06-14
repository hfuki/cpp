#include "Dog.hpp"

Dog::Dog()
{
        type = "Dog";
        brain = new Brain();
        std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(NULL)
{
        std::cout << "Dog copy constructor called\n";
        *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
        std::cout << "Dog copy assignment operator called\n";
        if (this != &other)
        {
                this->type = other.type;
                if (this->brain)
                        delete this->brain;
                this->brain = new Brain(*other.brain);
        }
        return *this;
}

Dog::~Dog()
{
        delete brain;
        std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
        std::cout << "Woof!\n";
}

Brain* Dog::getBrain() const
{
        return brain;
}
