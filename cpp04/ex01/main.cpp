#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
        std::cout << "---- Subject Array Test ----\n";
        const int N = 4;
        Animal* animals[N];

        for (int i = 0; i < N / 2; i++)
                animals[i] = new Dog();
        for (int i = N / 2; i < N; i++)
                animals[i] = new Cat();

        for (int i = 0; i < N; i++)
                delete animals[i];

        std::cout << "\n---- Deep Copy Test ----\n";
        Dog basic;
        {
                Dog tmp = basic;
        } // tmp goes out of scope, basic's brain should remain valid

        std::cout << "\n---- Detailed Brain Copy Test ----\n";
        Dog* dogA = new Dog();
        dogA->getBrain()->setIdea(0, "I want a bone");

        Dog* dogB = new Dog(*dogA);
        dogA->getBrain()->setIdea(0, "I want a ball");

        std::cout << "Dog A idea 0: " << dogA->getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog B idea 0: " << dogB->getBrain()->getIdea(0) << std::endl;

        delete dogA;
        delete dogB;

        return 0;
}