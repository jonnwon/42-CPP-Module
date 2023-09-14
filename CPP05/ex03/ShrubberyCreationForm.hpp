#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator <<(std::ostream& outputStream, const ShrubberyCreationForm& rhs);

#endif
