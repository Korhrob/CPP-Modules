#pragma once

class Fixed {

	private:
		int					value;
		static const int	frac = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed& operator= (const Fixed& copy);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};
