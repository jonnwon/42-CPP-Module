#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	ShrubberyCreationForm_test()
{
	try
	{
		Bureaucrat king("King", 1);
		Bureaucrat man("man", 149);
		ShrubberyCreationForm file1("TEST");


		std::cout << file1 << std::endl;
		man.signForm(file1); // can't sign
		std::cout << file1 << std::endl;

		king.executeForm(file1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	RobotomyRequestForm_test()
{
	try
	{
		Bureaucrat king("King", 1);
		Bureaucrat man("man", 149);
		RobotomyRequestForm file2("TEST");

		std::cout << file2 << std::endl;
		king.signForm(file2);	// can sign
		std::cout << file2 << std::endl;

		man.executeForm(file2);	// not execute
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	PresidentialPardonForm_test()
{
	try
	{
		Bureaucrat king("King", 1);
		PresidentialPardonForm file3("TEST");

		std::cout << file3 << std::endl;
		king.signForm(file3);		// can sign
		std::cout << file3 << std::endl;

		king.executeForm(file3);	// can execute
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	ShrubberyCreationForm_test();
//	RobotomyRequestForm_test();
//	PresidentialPardonForm_test();
	return 0;
}
