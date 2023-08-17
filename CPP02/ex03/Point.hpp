#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
		Point& operator=(const Point& rhs);

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		~Point();

		Fixed const& get_x() const;
		Fixed const& get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
