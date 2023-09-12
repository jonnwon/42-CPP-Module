#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test_construcot()
{
	try
	{
		Form a("AA", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_not_signed()
{
	try
	{
		Form a("AA", 10, 10);
		std::cout << a << std::endl;
		Bureaucrat man("MAN", 11);
		man.signForm(a);
		std::cout << a << std::endl;
		Bureaucrat error_man("throw error", 160);
		Bureaucrat ghost("not execute", 5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_signed()
{
	try
	{
		Form a("AA", 10, 10);
		std::cout << a << std::endl;
		Bureaucrat man("MAN", 10);
		man.signForm(a);
		std::cout << a << std::endl;
		Bureaucrat error_man("throw error", 160);
		Bureaucrat ghost("not execute", 5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	test_construcot();
	test_not_signed();
	test_signed();
	return 0;
}
