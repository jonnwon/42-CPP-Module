#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& rhs);
        ~Intern();

        AForm *makeForm(std::string const& form_name, std::string target);

		class NotExistForm : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

#endif
