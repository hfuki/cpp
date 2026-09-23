#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "===== 1. 正常な生成 =====\n";
	try
	{
		Bureaucrat alice("Alice", 42);
		std::cout << alice << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: " << e.what() << "\n";
	}

	std::cout << "\n===== 2. 境界値 1 と 150 =====\n";
	try
	{
		Bureaucrat top("Top", 1);
		Bureaucrat bottom("Bottom", 150);
		std::cout << top << "\n" << bottom << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: 1 と 150 は有効なはず: " << e.what() << "\n";
	}

	std::cout << "\n===== 3. grade 0 で生成 =====\n";
	try
	{
		Bureaucrat bad("Bad", 0);
		std::cout << "NG: 例外が出ていない " << bad << "\n";
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "OK: " << e.what() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: 例外の型が違う: " << e.what() << "\n";
	}

	std::cout << "\n===== 4. grade 151 で生成 =====\n";
	try
	{
		Bureaucrat bad("Bad", 151);
		std::cout << "NG: 例外が出ていない " << bad << "\n";
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "OK: " << e.what() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: 例外の型が違う: " << e.what() << "\n";
	}

	std::cout << "\n===== 5. increment / decrement の向き =====\n";
	try
	{
		Bureaucrat bob("Bob", 100);
		bob.incrementGrade();
		std::cout << "increment 後  : " << bob << "  (99 が正解)\n";
		bob.decrementGrade();
		bob.decrementGrade();
		std::cout << "decrement 2回 : " << bob << "  (101 が正解)\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: " << e.what() << "\n";
	}

	std::cout << "\n===== 6. grade 1 から increment =====\n";
	try
	{
		Bureaucrat top("Top", 1);
		top.incrementGrade();
		std::cout << "NG: 例外が出ていない " << top << "\n";
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "OK: " << e.what() << "\n";
	}

	std::cout << "\n===== 7. grade 150 から decrement =====\n";
	try
	{
		Bureaucrat bottom("Bottom", 150);
		bottom.decrementGrade();
		std::cout << "NG: 例外が出ていない " << bottom << "\n";
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "OK: " << e.what() << "\n";
	}

	std::cout << "\n===== 8. コピーと代入 =====\n";
	{
		Bureaucrat a("Alice", 10);
		Bureaucrat b("Bob", 100);

		Bureaucrat c(a);
		std::cout << "c(a)       : " << c << "\n";
		a = b;
		std::cout << "a = b の後 : " << a << "  (名前は Alice のまま)\n";
	}

	std::cout << "\nここまで到達すれば、例外で異常終了していない\n";
	return 0;
}
