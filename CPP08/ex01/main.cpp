#include "Span.hpp"

int main()
{
	try
	{
		Span a(10);

		for (int i=0; i<10; i+=2)
		{
			if (i == 2)	// || (i == 0)		// throw NotEnoughNumbersException
			{
				std::cout << "a.longesSpan: " << a.longestSpan() << std::endl;
				std::cout << "a.shortestSpan: " << a.shortestSpan() << std::endl;
			}
			a.addNumber(i);
		}
		a.print_info();

		std::vector<int> b;
		for (int i = 0; i < 5; i++)
			b.push_back(i);
		a.addNumber(b.begin(), b.end());

		a.print_info();
		std::cout << "a.longestSpan: " << a.longestSpan() << std::endl;
		std::cout << "a.shortestSpan: " << a.shortestSpan() << std::endl;

//		a.addNumber(123);		// throw NoSpaceException
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
