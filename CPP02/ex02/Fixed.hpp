
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

		Fixed& operator++ () const;
		Fixed& operator-- () const;
		Fixed operator++ (int) const;
		Fixed operator++ (int) const;

		friend std::ostream& operator<< (std::ostream &stream, const Fixed &fixed);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed&	Fixed::min(Fixed& a, Fixed& b) const
		Fixed&	Fixed::min(const Fixed& a, const Fixed& b) const
		Fixed&	Fixed::max(Fixed& a, Fixed& b) const
		Fixed&	Fixed::max(const Fixed& a, const Fixed& b) const

};
