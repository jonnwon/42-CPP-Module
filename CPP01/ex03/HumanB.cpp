#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: name(name), weapon(NULL) 
{
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;	
}

void HumanB::attack()
{
	if (weapon == NULL)
		std::cout << this->name << " has no weaopn" << std::endl;
	else
		std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& w)
{
	weapon = &w;
}
