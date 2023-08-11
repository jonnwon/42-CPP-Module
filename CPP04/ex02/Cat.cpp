#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	std::cout << "[Cat] : Defualt construcor called" << std::endl;
	type = "Cat";
	cat_brain = new Brain();
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
		delete cat_brain;
		cat_brain = new Brain(*rhs.cat_brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] : Destructor called" << std::endl;
	delete cat_brain;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] : make Sound" << std::endl;
}

std::string Cat::get_idea(int i)
{
	return cat_brain->getIdeaAtIndex(i);
}

void	Cat::set_idea(int i, const std::string& idea)
{
	cat_brain->set_Idea_At_Index(i, idea);
}
