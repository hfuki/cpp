#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
public:
	enum e_type
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO,
		INVALID
	};

private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter(void);

	static e_type detectType(const std::string& literal);
	static double toDouble(const std::string& literal, e_type type);

	static void printChar(double value, e_type type);
	static void printInt(double value, e_type type);
	static void printFloat(double value, e_type type);
	static void printDouble(double value, e_type type);

public:
	static void convert(const std::string& literal);
};

#endif