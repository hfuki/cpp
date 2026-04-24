#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{}

Fixed::Fixed(const int n)
{
	this->value = n << bits;
}

Fixed::Fixed(const float f)
{
	this->value = roundf(f * (1 << bits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
	return (this->value);
}

void	Fixed::setRawBits(int const n)
{
	this->value = n;
}

float	Fixed::toFloat() const
{
	return (float)this->value / (1 << bits);
}

int Fixed::toInt() const
{
	return this->value >> bits;
}

bool	Fixed::operator>(const Fixed& n) const
{
	return this->value > n.value;
}

bool	Fixed::operator<(const Fixed& n) const
{
	return this->value < n.value;
}

bool	Fixed::operator>=(const Fixed& n) const
{
	return this->value >= n.value;
}

bool	Fixed::operator<=(const Fixed& n) const
{
	return this->value <= n.value;
}

bool	Fixed::operator==(const Fixed& n) const
{
	return this->value == n.value;
}

bool	Fixed::operator!=(const Fixed& n) const
{
	return this->value != n.value;
}

Fixed	Fixed::operator+(const Fixed& n) const
{
	Fixed	res;
	res = Fixed(this->toFloat() + n.toFloat());
	return res;
}

Fixed	Fixed::operator-(const Fixed& n) const
{
	Fixed	res;
	res.value = this->value - n.value;
	return res;
}

Fixed	Fixed::operator*(const Fixed& n) const
{
	Fixed	res;
	res = Fixed(this->toFloat() * n.toFloat());
	return res;
}

Fixed	Fixed::operator/(const Fixed& n) const
{
	Fixed	res;
	res = Fixed(this->toFloat() / n.toFloat());
	return res;
}

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp;
	tmp = *this;
	this->value++;
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;
	tmp = *this;
	this->value--;
	return tmp;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a > b) ? b : a;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a > b) ? b : a;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
