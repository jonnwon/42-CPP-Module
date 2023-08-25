#include "Character.hpp"

Character::Character()
:name("Defualt")
{
	std::cout << "[Character] : Defualt construcor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		slot[i] = NULL;
	}
}

Character::Character(std::string const& name)
:name(name)
{
	std::cout << "[Character] : construcor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		slot[i] = NULL;
	}
}

Character::Character(const Character& other)
{
	std::cout << "[Character] : Copy constructor called" << std::endl;
	*this = other;
}

Character& Character::operator=(const Character& rhs)
{
	std::cout << "[Character] : Copy assignment operator called" << std::endl;
	std::cout << "test: "<< rhs.getName() << std::endl;
//	if (this != &rhs)
//	{
//		this->name = rhs.name;
//		for (int i = 0; i < 4; i++)
//		{
//			delete slot[i];
//			slot[i] = nullptr;
//		}
//	}
//
	return *this;
}



Character::~Character()
{
	std::cout << "[Character] : Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] != NULL)
			delete slot[i];
		slot[i] = NULL;
	}
}

std::string const& Character::getName() const
{
	return name;
}

