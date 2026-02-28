#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), next(0) {}

void	PhoneBook::addContact(const Contact& c)
{
	contacts[next] = c;
	next = (next + 1) % 8;
	if (count < 8)
		count++;
}

int PhoneBook::getCount() const
{
	return count;
}

std::string PhoneBook::format10(const std::string& s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void	PhoneBook::printTable() const
{
	if (count == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}

	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nick name" << std::endl;

	for (int i = 0; i < count; ++i)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << format10(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << format10(contacts[i].getLastName()) << "|"
				  << std::setw(10) << format10(contacts[i].getNickName()) << std::endl;
	}
}

void	PhoneBook::printDetailByIndex(int index) const
{
	if (index < 0 || index >= count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	const Contact& c = contacts[index];
	std::cout << "First name:" << c.getFirstName() << std::endl;	
	std::cout << "Last name:" << c.getLastName() << std::endl;
	std::cout << "Nickname:" << c.getNickName() << std::endl;	
	std::cout << "Phone number:" << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret:" << c.getDarkestSecret() << std::endl;
}