#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
:_name("Default"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExec(MIN_GRADE)
{
	std::cout << "[AForm] : Default Constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
:_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "[AForm] : Constructor called" << std::endl;
	if (_gradeToSign < MAX_GRADE || _gradeToExec < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > MIN_GRADE || _gradeToExec > MIN_GRADE)
		throw AForm::GradeTooLowException();
};

AForm::AForm(const AForm& other)
:_gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	std::cout << "[AForm] : Copy constructor called" << std::endl;

	*this = other;
}

AForm& AForm::operator=(const AForm& rhs)
{
	std::cout << "[AForm] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(_name) = rhs.getName();
		_signed = rhs.getSigned();
		const_cast<int&>(_gradeToSign) = rhs.getGradeToSign();
		const_cast<int&>(_gradeToExec) = rhs.getGradeToExec();
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "[AForm] : Destructor called" << std::endl;
}

std::string AForm::getName() const { return _name; }
bool		AForm::getSigned() const { return _signed; }
int			AForm::getGradeToSign() const { return _gradeToSign; }
int			AForm::getGradeToExec() const { return _gradeToExec; }

void		AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw AForm::GradeTooHighException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "[AForm] : Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "[AForm] : Grade is too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "[AForm] : Not signed!";
}

const char* AForm::TargetFileOpenError::what() const throw()
{
	return "[AForm] : Target file open error!";
}

std::ostream& operator <<(std::ostream& outputStream, const AForm& rhs)
{
	outputStream << "======================" << std::endl;
	outputStream << "Form name : " << rhs.getName() << std::endl;
	outputStream << "Form signed : " << rhs.getSigned() << std::endl;
	outputStream << "grade to sign : " << rhs.getGradeToSign() << std::endl;
	outputStream << "grade to excute : " << rhs.getGradeToExec() << std::endl;
	outputStream << "======================" << std::endl;

	return outputStream;
}
