#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& x)
{
	std::cout << x << " ";
}

void doubleInt(int& x)
{
	x *= 2;
}

class Awesome
{
private:
	int n;

public:
	Awesome(void) : n(0) {}
	Awesome(int v) : n(v) {}
	int getN(void) const { return n; }
};

std::ostream& operator<<(std::ostream& os, const Awesome& a)
{
	os << a.getN();
	return os;
}

int main(void)
{
	std::cout << "===== 1. int 配列を表示 =====\n";
	int nums[5] = {1, 2, 3, 4, 5};
	iter(nums, 5, printElement<int>);
	std::cout << "\n";

	std::cout << "\n===== 2. 要素を書き換える =====\n";
	iter(nums, 5, doubleInt);
	iter(nums, 5, printElement<int>);
	std::cout << "\n";

	std::cout << "\n===== 3. std::string 配列 =====\n";
	std::string words[3] = {"foo", "bar", "baz"};
	iter(words, 3, printElement<std::string>);
	std::cout << "\n";

	std::cout << "\n===== 4. 自作クラスの配列 =====\n";
	Awesome objs[4] = {Awesome(10), Awesome(20), Awesome(30), Awesome(40)};
	iter(objs, 4, printElement<Awesome>);
	std::cout << "\n";

	std::cout << "\n===== 5. 長さ 0 =====\n";
	iter(nums, 0, printElement<int>);
	std::cout << "  (何も出ていなければ正解)\n";

	return 0;
}