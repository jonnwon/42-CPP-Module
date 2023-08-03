#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("a");
	ClapTrap	b("b");

	ClapTrap	c = a;	// Copy constuctor (== c(a))
	c.print_status();

	c = b;				// Copy assignment operator
	c.print_status();

	a.attack("AAA");
	a.attack("AAA");
	a.attack("AAA");
	a.beRepaired(1);
	a.beRepaired(1);
	a.takeDamage(1);
	a.takeDamage(1);
	a.takeDamage(12);

	a.attack("AAA");
	a.beRepaired(3);
	return 0;
}
