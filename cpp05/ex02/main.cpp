#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "===== 1. 署名 → 実行（成功） =====\n";
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("home");

		std::cout << form << "\n";
		boss.signForm(form);
		boss.executeForm(form);
		std::cout << "  (home_shrubbery が作られたか確認すること)\n";
	}

	std::cout << "\n===== 2. 未署名のまま実行 =====\n";
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm form("Arthur");

		boss.executeForm(form);
		std::cout << "  (not signed で失敗するのが正解)\n";
	}

	std::cout << "\n===== 3. 署名済みだが grade 不足 =====\n";
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat clerk("Clerk", 140);
		PresidentialPardonForm form("Ford");

		boss.signForm(form);
		clerk.executeForm(form);
		std::cout << "  (grade too low で失敗するのが正解)\n";
	}

	std::cout << "\n===== 4. 境界値（grade == gradeToExecute == 5） =====\n";
	{
		Bureaucrat boss("Boss", 5);
		PresidentialPardonForm form("Zaphod");

		boss.signForm(form);
		boss.executeForm(form);
		std::cout << "  (成功するのが正解)\n";
	}

	std::cout << "\n===== 5. RobotomyRequestForm を5回 =====\n";
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm form("Marvin");

		boss.signForm(form);
		for (int i = 0; i < 5; i++)
			boss.executeForm(form);
		std::cout << "  (成功と失敗が混ざるのが正解)\n";
	}

	std::cout << "\n===== 6. AForm* でまとめて扱う =====\n";
	{
		Bureaucrat boss("Boss", 1);
		AForm* forms[3];

		forms[0] = new ShrubberyCreationForm("garden");
		forms[1] = new RobotomyRequestForm("Trillian");
		forms[2] = new PresidentialPardonForm("Slartibartfast");

		for (int i = 0; i < 3; i++)
		{
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
		}

		for (int i = 0; i < 3; i++)
			delete forms[i];
	}

	std::cout << "\n===== 7. execute を直接呼ぶ =====\n";
	try
	{
		Bureaucrat clerk("Clerk", 150);
		ShrubberyCreationForm form("direct");

		form.execute(clerk);
		std::cout << "NG: 例外が出ていない\n";
	}
	catch (AForm::FormNotSignedException& e)
	{
		std::cout << "OK: " << e.what() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "NG: 例外の型が違う: " << e.what() << "\n";
	}

	std::cout << "\nここまで到達すれば、例外で異常終了していない\n";
	return 0;
}
