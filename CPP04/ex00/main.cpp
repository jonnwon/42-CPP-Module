#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
//	const Animal* meta = new Animal();
//	const Animal* j = new Dog();
//	const Animal* i = new Cat();
//
//	std::cout << j->getType() << " " << std::endl;
//	std::cout << i->getType() << " " << std::endl;
//	i->makeSound(); //It will output the Cat sound!
//	j->makeSound();
//	meta->makeSound();
//
//	delete meta;
//	delete j;
//	delete i;
//
//	const WrongAnimal* wa = new WrongAnimal();
//	const WrongAnimal* wc = new WrongCat();
//
//	std::cout << wa->getType() << " " << std::endl;
//	std::cout << wc->getType() << " " << std::endl;
//	wa->makeSound();
//	wc->makeSound(); //It will output the WrongAnimal sound!
//
//	delete wa;
//	delete wc;
//
	Cat a;

	Cat b = a;

	std::cout  << b.getType() << std::endl;


	return 0;
}
