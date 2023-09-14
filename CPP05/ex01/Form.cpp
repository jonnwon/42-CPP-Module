#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
:_name("Default"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExec(MIN_GRADE)
{
	std::cout << "[Form] : Default Constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
:_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "[Form] : Constructor called" << std::endl;
	if (_gradeToSign < MAX_GRADE || _gradeToExec < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > MIN_GRADE || _gradeToExec > MIN_GRADE)
		throw Form::GradeTooLowException();
};

Form::Form(const Form& other)
:_gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	std::cout << "[Form] : Copy constructor called" << std::endl;

	*this = other;
}

Form& Form::operator=(const Form& rhs)
{
	std::cout << "[Form] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(_name) = rhs.getName();
		_signed = rhs.getSigned();
		const_cast<int&>(_gradeToSign) = rhs.getGradeToSign();
		const_cast<int&>(_gradeToExec) = rhs.getGradeToExec();
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "[Form] : Destructor called" << std::endl;
}

std::string Form::getName() const { return _name; }
bool		Form::getSigned() const { return _signed; }
int			Form::getGradeToSign() const { return _gradeToSign; }
int			Form::getGradeToExec() const { return _gradeToExec; }

void		Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw Form::GradeTooHighException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "[Form] : Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "[Form] : Grade is too low!";
}


std::ostream& operator <<(std::ostream& outputStream, const Form& rhs)
{
	outputStream << "======================" << std::endl;
	outputStream << "Form name : " << rhs.getName() << std::endl;
	outputStream << "Form signed : " << rhs.getSigned() << std::endl;
	outputStream << "grade to sign : " << rhs.getGradeToSign() << std::endl;
	outputStream << "grade to excute : " << rhs.getGradeToExec() << std::endl;
	outputStream << "======================" << std::endl;

	return outputStream;
}
