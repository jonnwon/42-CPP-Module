#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& rhs);
		~Cat();

		virtual void makeSound() const;

		std::string get_idea(int i);
		void	set_idea(int i, const std::string& idea);

	private:
		Brain*	cat_brain;
};

#endif
