#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
		AForm();
		AForm& operator=(const AForm& rhs);

	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		void		beSigned(const Bureaucrat &b);

		virtual void execute(Bureaucrat const & executor) const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class TargetFileOpenError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator <<(std::ostream& outputStream, const AForm& rhs);

#endif
