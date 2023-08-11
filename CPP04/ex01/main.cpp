#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	int cnt;

	// input number
	while (1)
	{
		std::cout << "Please enter the number of animals: ";
		std::cin >> cnt;
		if (cnt % 2 == 0)
			break ;
		else
		{
			std::cout << "Error: No even number!" << std::endl;
			continue;
		}
	}
	std::cout << "cnt: " << cnt << std::endl;

	Animal *animals[cnt];

	std::cout << std::endl << "=====Constructor test=====" << std::endl;
	for (int i = 0; i < cnt; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// print test
	std::cout << std::endl << "=====Print test=====" << std::endl;
	for (int i = 0; i < cnt; i++)
	{
		std::cout << "i[" << i << "]: " << animals[i]->get_type() << std::endl;
		animals[i]->makeSound();
	}

	std::cout << std::endl << "=====Delete test=====" << std::endl;
	for (int i = 0; i < cnt; i++)
	{
		std::cout << "i[" << i << "] delete " << std::endl;
		delete animals[i];
		std::cout << std::endl;
	}

	
	// deep copy test
	std::cout << std::endl << "=====Deep copy test=====" << std::endl;

	Cat originalCat;
	originalCat.makeSound();

	Cat copiedCat = originalCat;		// Copy constructor called


	copiedCat.set_idea(1, "tttest");	// Modify the copiedCat's brain

	// Output the brain contents of both original and copied cats
	std::cout << originalCat.get_idea(1) << std::endl;
	std::cout << copiedCat.get_idea(1) << std::endl;

	return 0;
}
