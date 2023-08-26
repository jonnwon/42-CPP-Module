#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
//	Animal a;	// Error

	int cnt = 4;
	Animal *animals[cnt];

	std::cout << std::endl << "=====Constructor test=====" << std::endl;
	for (int i = 0; i < cnt; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Makesound test
	std::cout << std::endl << "=====Makesound test=====" << std::endl;
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

	
	// Deep copy test
	std::cout << std::endl << "=====Deep copy test=====" << std::endl;

	Cat originalCat;
	originalCat.makeSound();

	Cat copiedCat;
	copiedCat = originalCat;		// Copy assignment operator test


	copiedCat.set_idea(1, "tttest");	// Modify the copiedCat's brain

	// Output the brain contents of both original and copied cats
	std::cout << "---------------------------" << std::endl;
	std::cout << "originalCat's idea: " << originalCat.get_idea(1) << std::endl;
	std::cout << "copiedCat's idea: " << copiedCat.get_idea(1) << std::endl;

	std::cout << "originalCat's idea: " << originalCat.get_idea(2) << std::endl;
	std::cout << "copiedCat's idea: "<< copiedCat.get_idea(2) << std::endl;
	std::cout << "---------------------------" << std::endl;

	Cat copiedCat2 = copiedCat;			// Copy constructor test

	std::cout << "copiedCat: " << copiedCat.get_idea(1) << std::endl;
	std::cout << "copiedCat2: " << copiedCat2.get_idea(1) << std::endl;


	copiedCat2.set_idea(1, "aaaaa");	// Modify the copiedCat2's brain
	
	std::cout << "--------Change idea--------"  << std::endl;

	std::cout << "copiedCat: " << copiedCat.get_idea(1) << std::endl;
	std::cout << "copiedCat2: " << copiedCat2.get_idea(1) << std::endl;


//	system("leaks I_don’t_want_to_set_the_world_on_fire");
	return 0;
}
