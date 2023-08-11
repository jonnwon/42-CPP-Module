#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal] : Defualt construcor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{

	std::cout << "[WrongAnimal] : Copy constructor called" << std::endl;
	*this = other;
}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "[WrongAnimal] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] : Destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] : make Sound" << std::endl;
}
