#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
//	Point a(0, 0);
//	Point b(5, 0);
//	Point c(2, 5);
//	Point point(2, 3);

	Point	a(0, 0);
	Point	b(10.5, 0);
	Point	c(5.5, 5.5);
	Point	point(5.5, 5.4);

	std::cout << bsp(a, b, c, point) << std::endl;

	return 0;
}
