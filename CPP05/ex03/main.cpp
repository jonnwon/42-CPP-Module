#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>

void	ShrubberyCreationForm_test()
{
	try
	{
		Intern						intern;
		ShrubberyCreationForm		*form;

		form = static_cast<ShrubberyCreationForm*>(intern.makeForm("shrubbery creation", "TEST"));
		std::cout << *form << std::endl;
		delete form;
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
		Intern					intern;
		RobotomyRequestForm		*form;

		form = static_cast<RobotomyRequestForm*>(intern.makeForm("robotomy request", "TEST"));
		std::cout << *form << std::endl;
		delete form;
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
		Intern						intern;
		PresidentialPardonForm		*form;

		form = static_cast<PresidentialPardonForm*>(intern.makeForm("presidential pardon", "TEST"));
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	NotExixtForm_test()
{
	try
	{
		Intern						intern;
		AForm						*form;

		form = static_cast<PresidentialPardonForm*>(intern.makeForm("bla bla bla", "TEST"));
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	ShrubberyCreationForm_test();
	RobotomyRequestForm_test();
	PresidentialPardonForm_test();
	NotExixtForm_test();

	return 0;
}
