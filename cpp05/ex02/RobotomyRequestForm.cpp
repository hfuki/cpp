#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

const std::string& RobotomyRequestForm::getTarget(void) const
{
	return target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkExecutable(executor);

	std::cout << "* BZZZZZZ... DRILLING NOISES... BZZZZZZ *\n";
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << "the robotomy of " << target << " failed\n";
}
