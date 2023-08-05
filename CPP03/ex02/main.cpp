#include "FragTrap.hpp"

int main()
{
	std::cout << "main test" << std::endl;

	FragTrap a("HI");
	FragTrap b = a;
	FragTrap c("Hello");

	a.print_status();
	b.print_status();	// Copy constructor test

	b = c;				// operator test
	b.print_status();

	b.attack("Bye");	// attack func test

	b.highFivesGuys();		//	highFivesGuys func test
	return 0;
}
