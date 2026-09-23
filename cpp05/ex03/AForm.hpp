#ifndef AForm_HPP
# define AForm_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

protected:
	void	checkExecutable(const Bureaucrat& executor) const;

public:
	AForm(void);
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm(void);

	const std::string& getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;

	void beSigned(const Bureaucrat& Bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif