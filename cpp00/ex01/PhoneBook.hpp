#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int		count;
	int		next;

	static std::string format10(const std::string& s);

public:
	PhoneBook();

	void addContact(const Contact& c);
	void printTable() const;
	void printDetailByIndex(int index) const;

	int	getCount() const;
};

#endif