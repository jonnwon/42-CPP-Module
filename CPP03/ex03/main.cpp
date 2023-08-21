#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("AAA");

	a.print_status();
	a.attack("enemy");
	a.highFivesGuys();
	a.guardGate();
	a.beRepaired(10);
	a.takeDamage(3);
	a.whoAmI();
	
	DiamondTrap b(a);			//copy constructor test
	b.print_status();
	b.whoAmI();

	DiamondTrap c("CCC");

	b = c;						// copy assignment operator test
	b.print_status();
	b.whoAmI();

	return 0;
}
