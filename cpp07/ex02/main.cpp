#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	std::cout << "===== 1. デフォルトコンストラクタ =====\n";
	{
		Array<int> empty;

		std::cout << "size = " << empty.size() << "   (0 が正解)\n";
		try
		{
			empty[0];
			std::cout << "NG: 例外が出ていない\n";
		}
		catch (std::exception& e)
		{
			std::cout << "OK: " << e.what() << "\n";
		}
	}

	std::cout << "\n===== 2. n 個の配列と初期値 =====\n";
	{
		Array<int> a(5);

		std::cout << "size = " << a.size() << "\n初期値: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << "  (全部 0 が正解)\n";
	}

	std::cout << "\n===== 3. 読み書き =====\n";
	{
		Array<int> a(5);

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = static_cast<int>(i) * 10;
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << "\n";
	}

	std::cout << "\n===== 4. コピーコンストラクタはディープコピーか =====\n";
	{
		Array<int> a(3);

		a[0] = 1;
		a[1] = 2;
		a[2] = 3;

		Array<int> b(a);
		b[0] = 999;

		std::cout << "a[0] = " << a[0] << "   (1 のままなら正解)\n";
		std::cout << "b[0] = " << b[0] << "\n";
	}

	std::cout << "\n===== 5. 代入演算子はディープコピーか =====\n";
	{
		Array<int> a(3);

		a[0] = 1;
		a[1] = 2;
		a[2] = 3;

		Array<int> c(1);
		c = a;
		c[0] = 777;

		std::cout << "a[0] = " << a[0] << "   (1 のままなら正解)\n";
		std::cout << "c[0] = " << c[0] << "\n";
		std::cout << "c.size() = " << c.size() << "   (3 が正解)\n";
	}

	std::cout << "\n===== 6. 範囲外アクセス =====\n";
	{
		Array<int> a(3);

		try
		{
			a[3] = 0;
			std::cout << "NG: 例外が出ていない\n";
		}
		catch (std::exception& e)
		{
			std::cout << "OK: " << e.what() << "\n";
		}
	}

	std::cout << "\n===== 7. std::string でも動くか =====\n";
	{
		Array<std::string> s(3);

		s[0] = "foo";
		s[1] = "bar";
		std::cout << "s[0]=[" << s[0] << "] s[1]=[" << s[1] << "] s[2]=[" << s[2] << "]\n";
	}

	std::cout << "\n===== 8. const な Array =====\n";
	{
		Array<int> a(3);

		a[0] = 42;

		const Array<int>& r = a;
		std::cout << "r[0] = " << r[0] << "   (const 版 operator[] が呼ばれる)\n";
	}

	return 0;
}
