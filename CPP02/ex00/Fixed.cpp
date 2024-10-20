#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (0);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}
