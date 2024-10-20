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

		bool operator> (const Fixed& src) const;
		bool operator< (const Fixed& src) const;
		bool operator>= (const Fixed& src) const;
		bool operator<= (const Fixed& src) const;
		bool operator== (const Fixed& src) const;
		bool operator!= (const Fixed& src) const;

		Fixed& operator+ (const Fixed& src);
		Fixed& operator- (const Fixed& src);
		Fixed& operator* (const Fixed& src);
		Fixed& operator/ (const Fixed& src);

		Fixed& operator++ ();
		Fixed& operator-- ();
		Fixed operator++ (int);
		Fixed operator-- (int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);

};

std::ostream& operator<< (std::ostream &stream, const Fixed &fixed);
