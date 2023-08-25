#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] : Defualt construcor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "[Cat] : Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "[Cat] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] : Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] : make Sound" << std::endl;
}
