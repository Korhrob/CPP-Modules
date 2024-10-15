#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int i) : value(i << frac)
{
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float f) : value(roundf(f * (1 < frac)))
{
	std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	value = src.getRawBits();
};

Fixed& Fixed::operator= (const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		value = src.getRawBits();

	return (*this);
};

bool	Fixed::operator< (const Fixed &b) const
{
	return (value < b.value);
};

bool	Fixed::operator> (const Fixed &b) const
{
	return (value > b.value);
};

bool	Fixed::operator<= (const Fixed &b) const
{
	return (value <= b.value);
};

bool	Fixed::operator>= (const Fixed &b) const
{
	return (value >= b.value);
},

bool	Fixed::operator== (const Fixed &b) const
{
	return (value == b.value);
};

bool	Fixed::operator!= (const Fixed &b) const
{
	return (value != b.value);
},

Fixed&	Fixed::operator+ (const Fixed &b)
{
	value += b.getRawBits();
	return (*this);
};

Fixed&	Fixed::operator- (const Fixed &b)
{
	value -= b.getRawBits();
	return (*this);
};

Fixed&	Fixed::operator* (const Fixed &b)
{
	value = (value * b.getRawBits()) >> frac;
	return (*this);
};

Fixed&	Fixed::operator/ (const Fixed &b)
{
	if (b.getRawBits() == 0)
		throw std::invalid_argument("Divison by zero");

	value = (value << frac) / b.getRawBits();
	return (*this);
};

Fixed& Fixed::operator++ ()
{
	value += 1 << frac;
	return (*this);
};

Fixed& Fixed::operator-- ()
{
	value -= 1 << frac;
	return (*this);
};

Fixed Fixed::operator++ (int)
{
	Fixed	temp = *this;

	value += 1 << frac;
	return (temp);
};

Fixed Fixed::operator++ (int)
{
	Fixed	temp = *this;

	value -= 1 << frac;
	return (temp);
};

std::ostream& operator<< (std::ostream &stream, const Fixed &src)
{
	stream << src.toFloat();
	return (stream);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
};

void	Fixed::setRawBits(int const raw)
{
	value = raw;
};

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << frac));
};

int		Fixed::toInt(void) const
{
	return (value >> frac);
};

Fixed&	Fixed::min(Fixed& a, Fixed& b) const
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::min(const Fixed& a, const Fixed& b) const
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) const
{
	if (a > b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(const Fixed& a, const Fixed& b) const
{
	if (a > b)
		return (a);
	return (b);
}