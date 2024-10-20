#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int i) : value(i << frac)
{
}

Fixed::Fixed(const float f) : value(static_cast<int>(roundf(f * (1 << frac))))
{
}

Fixed::Fixed(const Fixed &src) : value(src.getRawBits())
{
}

Fixed& Fixed::operator= (const Fixed &src)
{
	if (this == &src)
		return (*this);
	value = src.getRawBits();
	return (*this);
}

bool	Fixed::operator< (const Fixed &b) const
{
	return (value < b.value);
}

bool	Fixed::operator> (const Fixed &b) const
{
	return (value > b.value);
}

bool	Fixed::operator<= (const Fixed &b) const
{
	return (value <= b.value);
}

bool	Fixed::operator>= (const Fixed &b) const
{
	return (value >= b.value);
}

bool	Fixed::operator== (const Fixed &b) const
{
	return (value == b.value);
}

bool	Fixed::operator!= (const Fixed &b) const
{
	return (value != b.value);
}

Fixed&	Fixed::operator+ (const Fixed &b)
{
	value += b.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator- (const Fixed &b)
{
	value -= b.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator* (const Fixed &b)
{
	value = (value * b.getRawBits()) >> frac;
	return (*this);
}

Fixed&	Fixed::operator/ (const Fixed &b)
{
	if (b.getRawBits() == 0)
		throw std::invalid_argument("Divison by zero");
	value = (value << frac) / b.getRawBits();
	return (*this);
}

Fixed& Fixed::operator++ ()
{
	value += 1;
	return (*this);
}

Fixed& Fixed::operator-- ()
{
	value -= 1;
	return (*this);
}

Fixed Fixed::operator++ (int)
{
	Fixed	temp = *this;

	value += 1;
	return (temp);
}

Fixed Fixed::operator-- (int)
{
	Fixed	temp = *this;

	value -= 1;
	return (temp);
}

std::ostream& operator<< (std::ostream &stream, const Fixed &src)
{
	stream << src.toFloat();
	return (stream);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << frac));
}

int		Fixed::toInt(void) const
{
	return (value >> frac);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
