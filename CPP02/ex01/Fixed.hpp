#pragma once

#include <iostream>

class Fixed {

	private:
		int					value;
		static const int	frac = 8;

	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &copy);
		Fixed& operator= (const Fixed& copy);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream& operator<< (std::ostream &stream, const Fixed &fixed);
