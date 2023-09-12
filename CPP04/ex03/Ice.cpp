#include "Ice.hpp"

Ice::Ice()
:AMateria("ice")
{
	std::cout << "[Ice] : Defualt construcor called" << std::endl;
}

Ice::Ice(const Ice& other)
{
	std::cout << "[Ice] : Copy constructor called" << std::endl;
	*this = other;
}

Ice& Ice::operator=(const Ice& rhs)
{
	std::cout << "[Ice] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "[Ice] : Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *newIce = new Ice();

	return newIce;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}
