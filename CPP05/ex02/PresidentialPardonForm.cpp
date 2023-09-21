#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "[PresidentialPardonForm] : Default Constructor called" << std::endl;
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "[PresidentialPardonForm] : Constructor called" << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
:AForm(other)
{
	std::cout << "[PresidentialPardonForm] : Copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "[PresidentialPardonForm] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_target = rhs._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] : Destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << "[PresidentialPardonForm] : execute called" << std::endl;

	if (getSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

std::ostream& operator <<(std::ostream& outputStream, const PresidentialPardonForm& rhs)
{
	outputStream << "======================" << std::endl;
	outputStream << "Form target : " << rhs.getTarget() << std::endl;
	outputStream << "Form name : " << rhs.getName() << std::endl;
	outputStream << "Form signed : " << rhs.getSigned() << std::endl;
	outputStream << "grade to sign : " << rhs.getGradeToSign() << std::endl;
	outputStream << "grade to excute : " << rhs.getGradeToExec() << std::endl;
	outputStream << "======================" << std::endl;

	return outputStream;
}
