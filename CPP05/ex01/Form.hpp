#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
		Form();
		Form& operator=(const Form& rhs);

	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		~Form();

		std::string getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		void		beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

//std::ostream& operator <<(std::ostream& outputStream, const Form& rhs);

#endif
