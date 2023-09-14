#ifndef PRESIDENTALPARDONFORM
#define PRESIDENTALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator <<(std::ostream& outputStream, const PresidentialPardonForm& rhs);

#endif
