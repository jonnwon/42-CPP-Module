#include "Bureaucrat.hpp"

void	test_constructor()
{
	try
	{
		Bureaucrat a("A", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_incrementGrade()
{
	try
	{
		Bureaucrat a("A", 1);
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_decrementGrade()
{
	try
	{
		Bureaucrat a("A", 150);
		std::cout << a << std::endl;
		a.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	test_constructor();
	test_incrementGrade();
	test_decrementGrade();

	return 0;
}
