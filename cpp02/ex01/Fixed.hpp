#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int bits = 8;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& other);
	Fixed& operator = (const Fixed& other);
	~Fixed();

	float toFloat() const;
	int toInt() const;
	int	getRawBits() const;
	void	setRawBits(int const n) ;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
