#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
:x(0), y(0)
{
	std::cout << "[Point] : Default constructor called" << std::endl;
}

Point::Point(const float x, const float y)
: x(x), y(y)
{
    std::cout << "[Point] : Int constructor called" << std::endl;
}

Point::Point(const Point& other)
{
	std::cout << "[Point] : Copy constructor called" <<std::endl;
	*this = other;
}


Point& Point::operator=(const Point& rhs)
{
	std::cout << "[Point] : Copy assignment operator called" << std::endl;
	
	if (this != &rhs)
	{
		const_cast<Fixed&>(x) = rhs.get_x();
		const_cast<Fixed&>(y) = rhs.get_y();
	}
	return (*this);
}


Point::~Point()
{
	std::cout << "[Point] : Destructor called" << std::endl;
}

Fixed const& Point::get_x() const
{
	return x;
}

Fixed const& Point::get_y() const
{
	return y;
}
