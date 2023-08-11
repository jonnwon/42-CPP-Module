#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& rhs);
		~Dog();

		virtual void makeSound() const;

		std::string get_idea(int i);
		void	set_idea(int i, const std::string& idea);

	private:
		Brain* dog_brain;
};

#endif
