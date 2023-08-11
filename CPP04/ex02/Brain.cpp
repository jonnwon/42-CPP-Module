#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] : Defualt construcor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "idea";
}

Brain::Brain(const Brain& other)
{

	std::cout << "[Brain] : Copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "[Brain] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "[Brain] : Destructor called" << std::endl;
}

void	Brain::set_Idea_At_Index(int index, const std::string& idea)
{
	ideas[index] = idea;
}

std::string Brain::getIdeaAtIndex(int index) const
{
	return ideas[index];
}


