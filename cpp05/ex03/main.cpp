#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;

	std::cout << "===== 1. 3種類すべて作れるか =====\n";
	{
		const std::string names[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};

		for (int i = 0; i < 3; i++)
		{
			AForm* form = intern.makeForm(names[i], "Bender");
			if (form == NULL)
			{
				std::cout << "NG: NULL が返ってきた\n";
				continue;
			}
			std::cout << "  -> " << *form << "\n";
			delete form;
		}
	}

	std::cout << "\n===== 2. 存在しない名前 =====\n";
	{
		AForm* form = intern.makeForm("coffee request", "Bob");
		if (form == NULL)
			std::cout << "OK: NULL が返った\n";
		else
		{
			std::cout << "NG: 何か作られてしまった\n";
			delete form;
		}
	}

	std::cout << "\n===== 3. 名前は厳密一致か =====\n";
	{
		const std::string bad[3] = {
			"Shrubbery Creation",
			"shrubbery",
			"shrubbery creation "
		};

		for (int i = 0; i < 3; i++)
		{
			AForm* form = intern.makeForm(bad[i], "x");
			if (form == NULL)
				std::cout << "OK: 拒否された\n";
			else
			{
				std::cout << "NG: 通ってしまった\n";
				delete form;
			}
		}
	}

	std::cout << "\n===== 4. 作って署名して実行 =====\n";
	{
		Bureaucrat boss("Boss", 1);
		AForm* form = intern.makeForm("presidential pardon", "Arthur");

		if (form != NULL)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n===== 5. 正しい派生型が返っているか =====\n";
	{
		Bureaucrat boss("Boss", 1);
		AForm* form = intern.makeForm("shrubbery creation", "intern_test");

		if (form != NULL)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			std::cout << "  (intern_test_shrubbery ができていれば正解)\n";
			delete form;
		}
	}

	std::cout << "\n===== 6. grade 不足の官僚に渡す =====\n";
	{
		Bureaucrat clerk("Clerk", 150);
		AForm* form = intern.makeForm("presidential pardon", "Ford");

		if (form != NULL)
		{
			clerk.signForm(*form);
			clerk.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\nここまで到達すれば、例外で異常終了していない\n";
	return 0;
}
