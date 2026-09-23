#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "===== 1. Form の生成と表示 =====\n";
	try
	{
		Form tax("TaxForm", 50, 25);
		std::cout << tax << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: " << e.what() << "\n";
	}

	std::cout << "\n===== 2. gradeToSign が 0 =====\n";
	try
	{
		Form bad("Bad", 0, 50);
		std::cout << "NG: 例外が出ていない " << bad << "\n";
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << "OK: " << e.what() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: 例外の型が違う: " << e.what() << "\n";
	}

	std::cout << "\n===== 3. gradeToExecute が 151 =====\n";
	try
	{
		Form bad("Bad", 50, 151);
		std::cout << "NG: 例外が出ていない " << bad << "\n";
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "OK: " << e.what() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: 例外の型が違う: " << e.what() << "\n";
	}

	std::cout << "\n===== 4. 署名成功（grade 10 で gradeToSign 50） =====\n";
	try
	{
		Bureaucrat boss("Boss", 10);
		Form tax("TaxForm", 50, 25);

		std::cout << "署名前: " << tax << "\n";
		boss.signForm(tax);
		std::cout << "署名後: " << tax << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: " << e.what() << "\n";
	}

	std::cout << "\n===== 5. 署名失敗（grade 100 で gradeToSign 50） =====\n";
	try
	{
		Bureaucrat clerk("Clerk", 100);
		Form tax("TaxForm", 50, 25);

		clerk.signForm(tax);
		std::cout << "署名後: " << tax << "\n";
		std::cout << "  (signed: no のままが正解)\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: signForm は例外を外に漏らしてはいけない: " << e.what() << "\n";
	}

	std::cout << "\n===== 6. 境界値（grade == gradeToSign） =====\n";
	try
	{
		Bureaucrat exact("Exact", 50);
		Form tax("TaxForm", 50, 25);

		exact.signForm(tax);
		std::cout << "署名後: " << tax << "\n";
		std::cout << "  (signed: yes が正解)\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: " << e.what() << "\n";
	}

	std::cout << "\n===== 7. beSigned を直接呼ぶ =====\n";
	try
	{
		Bureaucrat clerk("Clerk", 100);
		Form tax("TaxForm", 50, 25);

		tax.beSigned(clerk);
		std::cout << "NG: 例外が出ていない\n";
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "OK: " << e.what() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: 例外の型が違う: " << e.what() << "\n";
	}

	std::cout << "\n===== 8. コピーと代入 =====\n";
	{
		Form a("A", 10, 10);
		Form b("B", 100, 100);
		Bureaucrat boss("Boss", 1);

		boss.signForm(b);
		a = b;
		std::cout << "a = b の後: " << a << "\n";
		std::cout << "  (name と grade は A のまま、signed だけ yes になる)\n";
	}

	std::cout << "\nここまで到達すれば、例外で異常終了していない\n";
	return 0;
}
