#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal();

		virtual	void	makeSound() const;
		std::string		get_type();
};

#endif
