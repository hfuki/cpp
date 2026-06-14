#include "Contact.hpp"

Contact::Contact()
	: firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("")
{}

void	Contact::set(
				const std::string& fn,
				const std::string& ln,
				const std::string& nn,
				const std::string& pn,
				const std::string& ds
				)
{
	firstName = fn;
	lastName = ln;
	nickName = nn;
	phoneNumber = pn;
	darkestSecret = ds;
}

const std::string& Contact::getFirstName() const { return firstName; }
const std::string& Contact::getLastName() const { return lastName; }
const std::string& Contact::getNickName() const { return nickName; }
const std::string& Contact::getPhoneNumber() const { return phoneNumber; }
const std::string& Contact::getDarkestSecret() const { return darkestSecret; }

bool Contact::isEmpty() const
{
	return firstName.empty() && lastName.empty() && nickName.empty() && phoneNumber.empty() && darkestSecret.empty();
}
