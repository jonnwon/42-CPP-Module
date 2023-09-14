#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "[Intern] : Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "[Intern] : Copy constructor called" << std::endl;
	*this = other;
}


Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

Intern::~Intern()
{
	std::cout << "[Intern] : Destructor called" << std::endl;
}


AForm* Intern::makeForm(std::string const& form_name, std::string target)
{
	std::cout << "[Intern] : makeForm called" << std::endl;
	
	AForm		*form;
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int			idx = -1;

	for (int i = 0; i < 3; i++)
	{
		if (form_name.compare(forms[i]) == 0)
		{
			idx = i;
			break;
		}
	}
	switch (idx)
	{
		case -1:
			throw NotExistForm();
			break;
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

const char* Intern::NotExistForm::what() const throw()
{
	return "This Form doesn't exist!";
}
