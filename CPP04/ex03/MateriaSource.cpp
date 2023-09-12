#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

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

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource] : Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] != NULL)
		{
			delete slot[i];
			slot[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	std::cout << "[MateriaSource] : learnMateria called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	std::cout << "[MateriaSource] : createMateria called" << std::endl;
	if (type != "cure" && type != "ice")
		return NULL;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] != NULL && slot[i]->getType().compare(type) == 0)
			return slot[i]->clone();
	}
	return NULL;
}
