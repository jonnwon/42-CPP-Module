#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	std::cout << "[Dog] : Defualt construcor called" << std::endl;
	type = "Dog";
	dog_brain = new Brain();
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
		delete dog_brain;
		dog_brain = new Brain(*rhs.dog_brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] : Destructor called" << std::endl;
	delete dog_brain;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] : make Sound" << std::endl;
}

std::string Dog::get_idea(int i)
{
	return dog_brain->getIdeaAtIndex(i);
}

void	Dog::set_idea(int i, const std::string& idea)
{
	dog_brain->set_Idea_At_Index(i, idea);
}
