#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

//#include "Fixed.hpp"
//
//int main(void)
//{
//	Fixed a;
//	Fixed b(2);
//	Fixed c(3.142f);
//	Fixed d(3.141f);
//
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	std::cout << c << std::endl;
//	std::cout << c.getRawBits() << std::endl;
//
//
//	bool tmp = (c != d);	 // 1
//	std::cout << tmp << std::endl;
//
//	return 0;
//}
