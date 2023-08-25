#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <stdio.h>

int main()
{
	Character a;
	AMateria *t = new Ice();
	AMateria *q = new Cure();
	AMateria *p = new Cure();
	AMateria *s = new Ice();
	AMateria *j = new Cure();
	


//	std::cout << a.getName() << std::endl;

	a.equip(t);
	a.equip(q);
	a.equip(p);
	a.equip(s);
	a.equip(j);
	for (int i = 0; i < 4; i++)
		a.print_slot_idx(i);

//	a.print_slot_idx(0);
//	a.print_slot_idx(1);
//	a.print_slot_idx(2);

	a.print_slot_addr();

	Character b;

	b = a;

	b.print_slot_addr();
	for (int i = 0; i < 4; i++)
		b.print_slot_idx(i);

	b.unequip(0);

	b.print_slot_addr();

	b.use(3, a);
//
//	b.print_slot_idx(0);
//	b.print_slot_idx(1);
//	a.print_slot_idx(2);
//
//

//	exit(1);

	system("leaks Interface_recap");

	return 0;
}
