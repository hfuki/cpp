#include "Cat.hpp"

Cat::Cat()
{
        type = "Cat";
        brain = new Brain();
        std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(NULL)
{
        std::cout << "Cat copy constructor called\n";
        *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
        std::cout << "Cat copy assignment operator called\n";
        if (this != &other)
        {
                this->type = other.type;
                if (this->brain)
                        delete this->brain;
                this->brain = new Brain(*other.brain);
        }
        return *this;
}

Cat::~Cat()
{
        delete brain;
        std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
        std::cout << "Meow!\n";
}

Brain* Cat::getBrain() const
{
        return brain;
}
