#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

	std::cout << "---- array delete test ----\n";
	const int N = 4;
	AAnimal* animals[N];

	for (int i = 0; i < N / 2; i++)
		animals[i] = new Dog();
	for (int i = N / 2; i < N; i++)
		animals[i] = new Cat();

	for (int i = 0; i < N; i++)
	{
		std::cout << animals[i]->getType() << " ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < N; i++)
		delete animals[i];

	std::cout << "---- deep copy test ----\n";
	Dog a;
	a.getBrain()->setIdea(0, "A-idea");

	Dog b(a); // copy ctor（deep copy）
	a.getBrain()->setIdea(0, "changed");

	std::cout << "a[0] = " << a.getBrain()->getIdea(0) << "\n";
	std::cout << "b[0] = " << b.getBrain()->getIdea(0) << "\n"; // "A-idea" ならOK

	return 0;
}
