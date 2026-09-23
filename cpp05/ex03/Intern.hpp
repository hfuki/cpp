#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class Intern
{
private:
	static AForm* makeShrubberyCreationForm(const std::string& target);
	static AForm* makeRobotomyRequestForm(const std::string& target);
	static AForm* makePresidentialPardonForm(const std::string& target);

public:
	Intern(void);
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern(void);

	AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif