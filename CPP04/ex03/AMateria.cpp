#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
:type("AMateria")
{
	std::cout << "[AMateria] : Defualt construcor called" << std::endl;
}

AMateria::AMateria(std::string const& type)
:type(type)
{
	std::cout << "[AMateria] : construcor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "[AMateria] : Copy constructor called" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	std::cout << "[AMateria] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] : Destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria class's use function." << " target: "<< target.getName() << std::endl; 
}
