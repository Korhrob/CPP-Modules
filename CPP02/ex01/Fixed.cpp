#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0 << frac;
};

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	value = i << frac;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	value = round(f * (1 << frac));
};

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	value = src.getRawBits();
};

Fixed& Fixed::operator= (const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = src.getRawBits();
};

std::ostream& operator<< (std::ostream &stream, const Fixed &src)
{
	stream << src.toFloat();
	return (stream);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
};

void	Fixed::setRawBits(int const raw)
{
	value = raw;
};

float	Fixed::toFloat(void)
{
	return (value / (1 << frac));
};

int		Fixed::toInt(void)
{
	return (value >> frac);
};
