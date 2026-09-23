#include "Form.hpp"

Form::Form(void)
		: name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
		: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
		: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form(void)
{}

const std::string& Form::getName(void) const
{
	return name;
}

bool Form::getIsSigned(void) const
{
	return isSigned;
}

int Form::getGradeToSign(void) const
{
	return gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Form: grade is too high";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Form: grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	os << "Form " << rhs.getName()
	   << ", signed: " << (rhs.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << rhs.getGradeToSign()
	   << ", grade to execute: " << rhs.getGradeToExecute() << ".";
	return os;
}