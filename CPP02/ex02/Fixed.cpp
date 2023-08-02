#include "Fixed.hpp"

Fixed::Fixed()
:m_raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : m_raw_bits(n << m_fractional_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : m_raw_bits(roundf(n * (1 << m_fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" <<std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	m_raw_bits = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	m_raw_bits = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(m_raw_bits) / (1 << m_fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (m_raw_bits >> m_fractional_bits);
}

/* comparison operators*/
bool	Fixed::operator>(const Fixed& rhs) const
{
	return (m_raw_bits > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (m_raw_bits < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (m_raw_bits >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (m_raw_bits <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (m_raw_bits == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (m_raw_bits != rhs.getRawBits());
}

/*arithmetic operators*/

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return Fixed(toFloat() / rhs.toFloat());
}

/*increment/decrement operator*/

Fixed&	Fixed::operator++()
{
	++m_raw_bits;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return tmp;
}

Fixed&	Fixed::operator--()
{
	--m_raw_bits;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return tmp;
}

/*static member func*/

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}


std::ostream& operator <<(std::ostream& outputStream, const Fixed& rhs)
{
	outputStream << rhs.toFloat();
	return outputStream;
}
