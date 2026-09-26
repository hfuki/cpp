#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:  return new A();
		case 1:  return new B();
		default: return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch (std::exception&) {}

	std::cout << "Unknown\n";
}

int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "===== 1. 型が既知のオブジェクトで検証 =====\n";
	{
		A a;
		B b;
		C c;

		std::cout << "A -> ptr: "; identify(&a);
		std::cout << "     ref: "; identify(a);
		std::cout << "B -> ptr: "; identify(&b);
		std::cout << "     ref: "; identify(b);
		std::cout << "C -> ptr: "; identify(&c);
		std::cout << "     ref: "; identify(c);
	}

	std::cout << "\n===== 2. generate() を8回 =====\n";
	for (int i = 0; i < 8; i++)
	{
		Base* p = generate();

		std::cout << "  ptr: "; identify(p);
		std::cout << "  ref: "; identify(*p);
		delete p;
	}

	std::cout << "\n===== 3. NULL を渡す =====\n";
	std::cout << "  ptr: "; identify(static_cast<Base*>(NULL));

	return 0;
}
