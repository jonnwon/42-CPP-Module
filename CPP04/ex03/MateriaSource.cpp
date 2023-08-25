#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "[MateriaSource] : Defualt construcor called" << std::endl;
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "[MateriaSource] : Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.slot[i] == NULL)
			this->slot[i] = NULL;
		else
		{
			if (other.slot[i]->getType().compare("ice") == 0)
				this->slot[i] = new Ice();
			else if (other.slot[i]->getType().compare("cure") == 0)
				this->slot[i] = new Cure();
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	std::cout << "[MateriaSource] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			if (slot[i] != NULL)
			{
				delete slot[i];
				slot[i] = NULL;
			}
			if (rhs.slot[i] != NULL && rhs.slot[i]->getType().compare("ice") == 0)
				this->slot[i] = new Ice();
			else if (rhs.slot[i] != NULL && rhs.slot[i]->getType().compare("cure") == 0)
				this->slot[i] = new Cure();
		}
	}
	return *this;
}


