#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "----Correct----";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << "\n";
	std::cout << i->getType() << "\n";

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "----Wrong----";
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << wa->getType() << "\n";
	std::cout << wc->getType() << "\n";

	wa->makeSound();
	wc->makeSound();

	delete wa;
	delete wc;

	std::cout << "----Brain----";
	Brain a;
	a.setIdea(0, "hello");

	Brain b(a);
	a.setIdea(0, "changed");

	std::cout << b.getIdea(0) << "\n"; 
}