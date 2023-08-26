#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#include <stdio.h>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	src->print_slot();

	Character* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	me->print_slot_addr();

	me->unequip(1);
	me->use(1, *bob);

	me->print_slot_addr();

	delete bob;
	delete me;
	delete src;
	delete tmp;

	system("leaks Interface_recap");
	return 0;
}

