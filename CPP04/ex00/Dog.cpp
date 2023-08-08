#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << "[Dog] : Defualt construcor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "[Dog] : Copy constructor called" << std::endl;
	*this = other;
}


Dog::Dog& operator=(const Dog& rhs)
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
	std::cout << "[Dog] : Destructor called, name: " << m_name << std::endl;
}

Dog::void makeSound()
{
	std::cout << "[Dog] : make Sound" << std::endl;
}
