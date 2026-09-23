#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	Form(void);
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form(void);

	const std::string& getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;

	void beSigned(const Bureaucrat& Bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif