#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0)
{
	std::cout <<"Default constructor called" << std::endl;

};

Fixed::Fixed(const int i) : value(i << frac)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : value (roundf(f * (1 << frac)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : value(src.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed &src)
{
	if (this == &src)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	value = src.getRawBits();
}

std::ostream& operator<< (std::ostream &stream, const Fixed &src)
{
	stream << src.toFloat();
	return (stream);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return (value / (1 << frac));
}

int		Fixed::toInt(void) const
{
	return (value >> frac);
}
