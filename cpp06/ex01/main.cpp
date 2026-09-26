#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data original;

	original.id = 42;
	original.name = "Arthur Dent";

	Data* ptr = &original;

	std::cout << "===== 1. 往復させる =====\n";
	uintptr_t raw = Serializer::serialize(ptr);
	Data* back = Serializer::deserialize(raw);

	std::cout << "元のポインタ   : " << ptr << "\n";
	std::cout << "uintptr_t の値 : " << raw << "\n";
	std::cout << "戻したポインタ : " << back << "\n";

	std::cout << "\n===== 2. アドレスは一致するか =====\n";
	if (ptr == back)
		std::cout << "OK: 完全に同じアドレス\n";
	else
		std::cout << "NG: アドレスが変わった\n";

	std::cout << "\n===== 3. データは読めるか =====\n";
	std::cout << "back->id   = " << back->id << "\n";
	std::cout << "back->name = " << back->name << "\n";

	std::cout << "\n===== 4. 同じオブジェクトを指しているか =====\n";
	back->id = 999;
	std::cout << "back->id を 999 にした\n";
	std::cout << "original.id = " << original.id << "   (999 なら同一)\n";

	std::cout << "\n===== 5. NULL の往復 =====\n";
	uintptr_t nullRaw = Serializer::serialize(NULL);
	Data* nullBack = Serializer::deserialize(nullRaw);

	std::cout << "serialize(NULL) = " << nullRaw << "\n";
	if (nullBack == NULL)
		std::cout << "OK: NULL のまま戻った\n";
	else
		std::cout << "NG: NULL でなくなった\n";

	return 0;
}
