#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

void	ShrubberyCreationForm_test()
{
	try
	{
		Bureaucrat man("King", 149);
		ShrubberyCreationForm file1("TEST");
		man.signForm(file1); // can't sign
		file1.execute(man);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	ShrubberyCreationForm_test();
	return 0;
}
