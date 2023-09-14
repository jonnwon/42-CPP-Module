#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "[RobotomyRequestForm] : Default Constructor called" << std::endl;
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "[RobotomyRequestForm] : Constructor called" << std::endl;
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
:AForm(other)
{
	std::cout << "[RobotomyRequestForm] : Copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "[RobotomyRequestForm] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_target = rhs._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] : Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::cout << "[RobotomyRequestForm] : execute called" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(0)));

	if (getSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "* Drrr Drrr Drrr *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been successfully robotized!" << std::endl;
	else
		std::cout << _target << " failed to robotized!" << std::endl;
}

std::ostream& operator <<(std::ostream& outputStream, const RobotomyRequestForm& rhs)
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
