#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int	m_raw_bits;
		static const int m_fractional_bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
