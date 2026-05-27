#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Brain a;
	a.setIdea(0, "hello");

	Brain b(a);
	a.setIdea(0, "changed");

	std::cout << b.getIdea(0) << "\n"; 
}