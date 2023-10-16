#include "Span.hpp"

void	general_test()
{
	srand(time(0));
	try	
	{
		Span a(10);

		for (int i = 0; i < 10; i++)
		{
//			if (i == 1)							// throw NotEnoughNumbersException
//			{
//				std::cout << "a.shortestSpan: " << a.shortestSpan() << std::endl;	// print e.waht() 
//				std::cout << "a.longestSpan: " << a.longestSpan() << std::endl;		// no print
//			}
			a.addNumber(rand() % 10);
		}
//		a.addNumber(rand() % 10);				// throw NoSpaceException
		a.print_info();
		std::cout << "a.shortestSpan: " << a.shortestSpan() << std::endl;
		std::cout << "a.longestSpan: " << a.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	addRange_test()
{
	srand(time(0));
	try	
	{
		std::list<int> list;
		Span a(10000);

		for (int i = 0; i < 10000; i++)
			list.push_back(rand() % 10);

//		std::list<int>::iterator it;		// print list
//		std::cout << "list: ";
//		for (it = list.begin(); it != list.end(); ++it) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;

//		a.addNumber(1);						// throw NoSpaceException

		a.addRange(list.begin(), list.end());
		a.print_info();

		std::cout << "a.shortestSpan: " << a.shortestSpan() << std::endl;
		std::cout << "a.longestSpan: " << a.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}

int main()
{
	general_test();
//	addRange_test();

	return 0;
}
