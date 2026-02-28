#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>


static bool readNonEmptyLine(const std::string& prompt, std::string& out)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return false;

		if (!out.empty())
			return true;
		
		std::cout << "Field cannot be empty. Try again." << std::endl;
	}
}
static bool isAllDigits(const std::string& s)
{
	if (s.empty())
		return false;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

static void doAdd(PhoneBook& pb)
{
	std::string fn, ln, nn, pn, ds;

	if (!readNonEmptyLine("First name:", fn)) return;
	if (!readNonEmptyLine("Last name:", ln)) return;
	if (!readNonEmptyLine("Nickname:", nn)) return;
	if (!readNonEmptyLine("Phone number:", pn)) return;
	if (!readNonEmptyLine("Darkest secret:", ds)) return;

	Contact c;
	c.set(fn, ln, nn, pn, ds);
	pb.addContact(c);

	std::cout << "Contact saved." << std::endl;
}

static void doSearch(PhoneBook& pb)
{
	pb.printTable();
	if (pb.getCount() == 0)
		return;

	std::string s;
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, s))
		return;

	if (!isAllDigits(s))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	int idx = std::atoi(s.c_str());
	pb.printDetailByIndex(idx);
}

int	main()
{
	PhoneBook	pb;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break;

		if (cmd == "ADD")
			doAdd(pb);
		else if (cmd == "SEARCH")
			doSearch(pb);
		else if (cmd == "EXIT")
			break;
		else if (cmd.empty())
			continue;
		else
			std::cout << "Unknow command." << std::endl;
	}
	return 0;
}

