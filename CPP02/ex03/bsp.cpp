#include "Point.hpp"

bool check_edge(const Point& line_p1, const Point& line_p2, const Point& point)
{
	float p1_x = line_p1.get_x().toFloat();
	float p1_y = line_p1.get_y().toFloat();

	float p2_x = line_p2.get_x().toFloat();
	float p2_y = line_p2.get_y().toFloat();
	
	float _x = point.get_x().toFloat();
	float _y = point.get_y().toFloat();

	return ((p2_y - p1_y) * _x + (p1_x - p2_x) * _y + p2_x * p1_y - p1_x * p2_y == 0);
}

float my_abs(float value)
{
	return (value < 0) ? -value : value;
}

float get_area(const Point& p1, const Point& p2, const Point& p3)
{
	float res;

	float p1_x = p1.get_x().toFloat();
	float p1_y = p1.get_y().toFloat();

	float p2_x = p2.get_x().toFloat();
	float p2_y = p2.get_y().toFloat();

	float p3_x = p3.get_x().toFloat();
	float p3_y = p3.get_y().toFloat();

	res = my_abs((p1_x * p2_y + p2_x * p3_y + p3_x * p1_y) - (p2_x * p1_y + p3_x * p2_y + p1_x * p3_y));
	res = res / 2;
	return res;
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool res;

	float total = get_area(a, b, c);
	float area_1 = get_area(point, b, c);
	float area_2 = get_area(a, point, c);
	float area_3 = get_area(a, b, point);

	if (total == (area_1 + area_2 + area_3) && !check_edge(a, b, point) \
		&& !check_edge(a, c, point) && !check_edge(b, c, point))
	{
		res = true;
	}
	else
		res = false;
	return res;
}
