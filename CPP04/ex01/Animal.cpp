#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal] : Defualt construcor called" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal& other)
{

	std::cout << "[Animal] : Copy constructor called" << std::endl;
	*this = other;
}


Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "[Animal] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "[Animal] : Destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "[Animal] : make Sound" << std::endl;
}

std::string	Animal::get_type()
{
	return type;
}

void	Animal::set_type(std::string type)
{
	this->type = type;
}

