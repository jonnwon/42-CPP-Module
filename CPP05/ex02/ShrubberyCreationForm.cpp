#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "[ShrubberyCreationForm] : Default Constructor called" << std::endl;
	_target = "default";
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
:AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "[ShrubberyCreationForm] : Constructor called" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
:AForm(other)
{
	std::cout << "[ShrubberyCreationForm] : Copy constructor called" << std::endl;
	*this = other;
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "[ShrubberyCreationForm] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] : Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << "[ShrubberyCreationForm] : execute called" << std::endl;

	std::string file_name = _target + "_shrubbery";
	std::string tree = 
		  "    ###    \n"
		  "   #o###   \n"
          " #####o### \n"
          "#o#\\#|#/###\n"
          " ###\\|/#o# \n"
          "  # }|{  # \n"
          "   #}|{ #  \n";

	if (getSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream ofs(file_name.c_str());
	if (!ofs.is_open())
		throw AForm::TargetFileOpenError();
	ofs << tree;
	ofs.close();
}

std::ostream& operator <<(std::ostream& outputStream, const ShrubberyCreationForm& rhs)
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
