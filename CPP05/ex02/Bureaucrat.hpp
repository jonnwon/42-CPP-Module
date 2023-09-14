#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
				virtual const char* what() const throw();
		};

		void		signForm(AForm &f) const;
};

std::ostream& operator <<(std::ostream& outputStream, const Bureaucrat& rhs);

#endif
