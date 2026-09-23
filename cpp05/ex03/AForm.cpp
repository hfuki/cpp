#include "AForm.hpp"

AForm::AForm(void)
		: name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
		: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
		: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm(void)
{}

const std::string& AForm::getName(void) const
{
	return name;
}

bool AForm::getIsSigned(void) const
{
	return isSigned;
}

int AForm::getGradeToSign(void) const
{
	return gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "AForm: grade is too high";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "AForm: grade is too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	os << "AForm " << rhs.getName()
	   << ", signed: " << (rhs.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << rhs.getGradeToSign()
	   << ", grade to execute: " << rhs.getGradeToExecute() << ".";
	return os;
}

void AForm::checkExecutable(const Bureaucrat& executor) const 
{
	if (!isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return "AForm: form is not signed";
}