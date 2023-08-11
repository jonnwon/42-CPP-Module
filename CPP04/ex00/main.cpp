#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *a = new Cat;
	WrongAnimal *b = new WrongCat;

	a->makeSound();
	b->makeSound();

	delete a;
	delete b;
	return 0;
}
