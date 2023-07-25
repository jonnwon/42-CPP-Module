#include "Zombie.hpp"

Zombie::Zombie() {
	this->index = 0;
}

Zombie::~Zombie() 
{
	std::cout << this->name << this->index << ": Destructor called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << this->index << ": BraiiiiiiinnnzzzZ..." << std::endl;	
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::set_index(int index)
{
	this->index = index;
}
