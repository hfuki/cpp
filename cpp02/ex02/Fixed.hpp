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

	float	toFloat() const;
	int	toInt() const;
	int	getRawBits() const;
	void	setRawBits(int const n) ;

	bool	operator>(const Fixed& n) const;
	bool	operator<(const Fixed& n) const;
	bool	operator>=(const Fixed& n) const;
	bool	operator<=(const Fixed& n) const;
	bool	operator==(const Fixed& n) const;
	bool	operator!=(const Fixed& n) const;

	Fixed operator+(const Fixed& n) const;
	Fixed operator-(const Fixed& n) const;
	Fixed operator*(const Fixed& n) const;
	Fixed operator/(const Fixed& n) const;

	Fixed&	operator++() ;
	Fixed	operator++(int) ;
	Fixed&	operator--() ;
	Fixed	operator--(int) ;

	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
