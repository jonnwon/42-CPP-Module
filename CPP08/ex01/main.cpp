#include "Span.hpp"
#include <cstdlib>
#include <deque>
#include <exception>
#include <list>
#include <ratio>
#include <vector>

//int main()
//{
//	try
//	{
//		Span a(10);
//
//		for (int i = 0; i < 10; i += 2)
//		{
////			if (i == 2)	// || (i == 0)		// throw NotEnoughNumbersException
////			{
////				std::cout << "a.longesSpan: " << a.longestSpan() << std::endl;
////				std::cout << "a.shortestSpan: " << a.shortestSpan() << std::endl;
////			}
//			a.addNumber(i);
//		}
//		a.print_info();
//		std::cout << "a.shortestSpan: " << a.shortestSpan() << std::endl;
//
//
////		std::vector<int> b;
////		for (int i = 0; i < 5; i++)
////			b.push_back(i);
////		a.addNumber(b.begin(), b.end());
////
////		a.print_info();
////		std::cout << "a.longestSpan: " << a.longestSpan() << std::endl;
////		std::cout << "a.shortestSpan: " << a.shortestSpan() << std::endl;
//
////		a.addNumber(123);		// throw NoSpaceException
//	}
//	catch (std::exception &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//
//	return 0;
//}


int main()
{
	try	// vector addRange test , a lot of num test
	{
		std::vector<int> b;

		Span a(10000);

		std::srand(std::time(0));

		for (int i = 0; i < 10000; i++)
			b.push_back(rand() % 10);

		a.addRange<std::vector<int>::iterator>(b.begin(), b.end());

		a.print_info();
		std::cout << "shortestSpan: " << a.shortestSpan() << std::endl;
		std::cout << "longesSpan: " << a.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
//
//	try	// list addRange test
//	{
//		std::list<int> c;
//		Span a(5);
//
//		for (int i = 0; i < 5; i++)
//			c.push_back(i);
//
//		std::list<int>::iterator it;
//		std::cout << "list: ";
//		for (it = c.begin(); it != c.end(); ++it) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//
//		a.addRange(c.begin(), c.end());
//		a.print_info();
//	}
//	catch (std::exception &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//
//	try
//	{
//		std::deque<int> d;
//
//		Span a(5);
//
//		for (int i = 0; i < 5; i++)
//			d.push_back(i);
//
//		std::deque<int>::iterator it;
//
//		std::cout << "deque: ";
//		for (it = d.begin(); it != d.end(); ++it)
//		{
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//
//		a.addRange(d.begin(), d.end());
//		a.print_info();
//	}
//	catch (std::exception &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
}

