#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator <<(std::ostream& outputStream, const RobotomyRequestForm& rhs);

#endif
