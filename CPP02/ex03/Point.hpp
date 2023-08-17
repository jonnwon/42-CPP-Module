#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point& operator=(const Point& rhs);
		~Point();

		Fixed const& get_x() const;
		Fixed const& get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
