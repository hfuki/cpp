#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact 
{
	private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	public:
	Contact();

	void	set
			(
				const std::string& fn,
				const std::string& ln,
				const std::string& nn,
				const std::string& pn,
				const std::string& ds
			);

	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickName() const;
	const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;

	bool isEmpty() const;

};

#endif 