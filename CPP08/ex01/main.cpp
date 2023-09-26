#include "Span.hpp"

int main()
{
	try
	{
		Span a(5);

		for (int i=0; i< 5; i++)
		{
			a.print_index();
			a.addNumber(i);
		}
		a.addNumber(5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

//	a.print_info();

//	std::cout << "copy constructor test" << std::endl;
//
//	Span b(a);
//
//	b.print_info();
//
//	b.replaceNumber();		// 1 -> 10000
//
//	b.print_info();			// ok
//	a.print_info();			// different with b
//	
//
//	std::cout << "Copy assignment operator test" << std::endl;
//	Span c;
//
//	c = b;
//
//	c.print_info();		// ok 
//
//	
//	std::cout << "Add number test" << std::endl;
//
//
//	for (int i = 5; i < 10; i++)
//		c.addNumber(i);
//	c.print_info();		// ok
//
	//////////////////////////////////////////////////////

	return 0;
}
