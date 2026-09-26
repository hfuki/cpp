#include <cctype>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <sstream>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{}

static bool isPseudoLiteral(const std::string& s)
{
	return (s == "nan" || s == "nanf" || s == "inf"
			|| s == "inf" || s == "inff" || s == "+inf"
			|| s == "+inff" || s == "-inf" || s == "-inff");
}

static bool isIntLiteral(const std::string& s)
{
	size_t i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i >= s.length())
		return false;
	while (i < s.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
		i++;
	}
	return true;
}

static bool isDoubleLiteral(const std::string& s)
{
	size_t i = 0;
	bool hasDigit = false;
	bool hasDot = false;

	if (s.empty())
		return false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (i < s.length())
	{
		if (std::isdigit(static_cast<unsigned char>(s[i])))
			hasDigit = true;
		else if (s[i] == '.' && !hasDot)
			hasDot = true;
		else 
			return false;
		i++;
	}
	return (hasDigit && hasDot);
}

static bool isFloatLiteral(const std::string& s)
{
	if (s.length() < 2 || s[s.length() - 1] != 'f')
		return false;
	return isDoubleLiteral(s.substr(0, s.length() - 1));
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string& literal)
{
	if (literal.empty())
		return INVALID;
	if (isPseudoLiteral(literal))
		return PSEUDO;
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
		return CHAR;
	if (isIntLiteral(literal))
		return INT;
	if (isFloatLiteral(literal))
		return FLOAT;
	if (isDoubleLiteral(literal))
		return DOUBLE;
	return INVALID;
}

double ScalarConverter::toDouble(const std::string& literal, e_type type)
{
	if (type == CHAR)
		return static_cast<double>(literal[0]);
	return std::strtod(literal.c_str(), NULL);
}

void ScalarConverter::printChar(double value, e_type type)
{
	std::cout << "char: ";
	if (type == PSEUDO || value < 0.0 || value > 127.0)
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";
}

void ScalarConverter::printInt(double value, e_type type)
{
	std::cout << "int: ";
	if (type == PSEUDO
			|| value < static_cast<double>(std::numeric_limits<int>::min())
			|| value > static_cast<double>(std::numeric_limits<int>::max()))
			std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";
}

void ScalarConverter::printFloat(double value, e_type type)
{
	float f = static_cast<float>(value);
	std::ostringstream oss;

	oss << f;
	std::string s = oss.str();

	std::cout << "float: " << s;
	if (type != PSEUDO
		&& s.find('.') == std::string::npos
		&& s.find('e') == std::string::npos
		&& s.find("inf") == std::string::npos)
		std::cout << ".0";
	std::cout << "f\n";
}

void ScalarConverter::printDouble(double value, e_type type)
{
	std::ostringstream oss;

	oss << value;
	std::string s = oss.str();

	std::cout << "double: " << s;
	if (type != PSEUDO
		&& s.find('.') == std::string::npos
		&& s.find('e') == std::string::npos
		&& s.find("inf") == std::string::npos)
		std::cout << ".0";
	std::cout << "\n";
}


void ScalarConverter::convert(const std::string& literal)
{
	e_type type = detectType(literal);

	if (type == INVALID)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	double value = toDouble(literal, type);

	printChar(value, type);	
	printInt(value, type);
	printFloat(value, type);
	printDouble(value, type);

}