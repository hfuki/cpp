#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << "--- 等しいときは2番目を返すか ---\n";
	int e = 5;
	int f = 5;
	std::cout << "  &e = " << &e << "   &f = " << &f << "\n";
	std::cout << "  &min(e, f) = " << &::min(e, f) << "   (f と同じなら正解)\n";
	std::cout << "  &max(e, f) = " << &::max(e, f) << "   (f と同じなら正解)\n";

	std::cout << "--- double でも動くか ---\n";
	double g = 1.5;
	double h = 0.5;
	std::cout << "  min = " << ::min(g, h) << "   max = " << ::max(g, h) << "\n";

	return 0;
}
