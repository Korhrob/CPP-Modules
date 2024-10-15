#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
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

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

Fixed::getRawBits(void) {
	std::cout << "getRawBits member function called" << std::endl;
	return (0);
};

Fixed::setRawBits(int const raw) {
	value = raw;
};