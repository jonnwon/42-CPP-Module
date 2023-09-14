#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat()
:_name("Default"), _grade(MIN_GRADE)
{
	std::cout << "[Bureaucrat] : Default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade)
	:_name(name), _grade(grade)
{
	std::cout << "[Bureaucrat] : Constructor called" << std::endl;
	if (_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "[Bureaucrat] : Copy constructor called" << std::endl;

	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "[Bureaucrat] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(_name) = rhs.getName();
		_grade = rhs.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] : Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const { return _name; }
int	Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
	_grade--;
	if (_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	_grade++;
	if (_grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "[Bureaucrat] : Grade is too high!";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "[Bureaucrat] : Grade is too low!";
};

std::ostream& operator <<(std::ostream& outputStream, const Bureaucrat& rhs)
{
	outputStream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return outputStream;
}

void Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
	}
}


void		Bureaucrat::executeForm(AForm const & form)
{
	//<bureaucrat> executed <form>
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
