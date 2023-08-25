#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] : Defualt construcor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "[Dog] : Copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] : Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] : make Sound" << std::endl;
}
