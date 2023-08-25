#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character()
:name("Defualt")
{
	std::cout << "[Character] : Defualt construcor called" << std::endl;
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(std::string const& name)
:name(name)
{
	std::cout << "[Character] : construcor called" << std::endl;
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}


//(cmd.compare("EXIT") == 0 

Character::Character(const Character& other)		// Need correction
{
	std::cout << "[Character] : Copy constructor called" << std::endl;
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

Character& Character::operator=(const Character& rhs)		// Need test 
{
	std::cout << "[Character] : Copy assignment operator called" << std::endl;
	std::cout << "test: "<< rhs.getName() << std::endl;
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

Character::~Character()
{
	std::cout << "[Character] : Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] != NULL)
		{
			delete slot[i];
			slot[i] = NULL;
		}
	}
}

std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	std::cout << "[Character] : equip called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	std::cout << "[Character] : unequip called" << std::endl;
	if (idx < 0 || idx > 3)
		return ;
	if (slot[idx] != NULL)
		slot[idx] = NULL;
}

//void Character::use(int idx, ICharacter &target) {
//  slot_[idx]->use(target);
//}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (slot[idx] != NULL)
		slot[idx]->use(target);
}
