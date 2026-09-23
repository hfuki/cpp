#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

const std::string& ShrubberyCreationForm::getTarget(void) const
{
	return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkExecutable(executor);

	std::ofstream ofs((target + "_shrubbery").c_str());
	if (!ofs)
	{
		std::cerr << "ShrubberyCreationForm: cannot open file\n";
		return;
	}
	
	ofs << "       ###\n";
	ofs << "      #####\n";
	ofs << "     #######\n";
	ofs << "    #########\n";
	ofs << "   ###########\n";
	ofs << "       ###\n";
	ofs << "       ###\n";
	ofs.close();
}
