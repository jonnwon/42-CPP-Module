#include "Cure.hpp"

Cure::Cure()
:AMateria("cure")
{
	std::cout << "[Cure] : Defualt construcor called" << std::endl;
}

Cure::Cure(const Cure& other)
{
	std::cout << "[Cure] : Copy constructor called" << std::endl;
	*this = other;
}

Cure& Cure::operator=(const Cure& rhs)
{
	std::cout << "[Cure] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "[Cure] : Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	Cure *newCure = new Cure();

	return newCure;
}

// Cure: "* heals <name>¡¯s wounds *"


void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
