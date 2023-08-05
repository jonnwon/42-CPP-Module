#include "ScavTrap.hpp"

int main()
{
	std::cout << "main test" << std::endl;

	ScavTrap a("HI");
	ScavTrap b = a;
	ScavTrap c("Hello");

	a.print_status();
	b.print_status();	// Copy constructor test

	b = c;				// operator test
	b.print_status();

	b.attack("Bye");	// attack func test

	b.guardGate();		//	guardGate gunc test
	return 0;
}
