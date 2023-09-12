#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "[WrongCat] : Defualt construcor called" << std::endl;
	type = "WrongCat";
}


WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "[WrongCat] : Copy constructor called" << std::endl;
	*this = other;
}


WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "[WrongCat] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] : Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] : make Sound" << std::endl;
}
