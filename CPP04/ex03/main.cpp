#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(1);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	delete tmp;	// If it don't use, leaks error. It can check with lldb


/////////// Deep copy test //////////////

//	IMateriaSource* src = new MateriaSource();
//	src->learnMateria(new Ice());
//	src->learnMateria(new Cure());
//
//	Character me = Character("me");
//	ICharacter* bob = new Character("bob");
//
//	AMateria* tmp;
//
//	tmp = src->createMateria("ice");
//	me.equip(tmp);
//
//	me.use(0, *bob);
//
//	Character you = me;		// Copy constructor deep copy test
//
////	Character you;			// Copy assignment deep copy test
////	you = me;
//
//	std::cout << "you" << std::endl;
//	you.use(0, *bob);
//
//	std::cout << "me" << std::endl;
//	me.use(0, *bob);
//
//	std::cout << "------unequip test------" << std::endl;
//	me.unequip(0);
//
//	std::cout << "you" << std::endl;
//	you.use(0, *bob);
//
//	std::cout << "me" << std::endl;
//	me.use(0, *bob);
//
//	delete bob;
//	delete src;
//	delete tmp;

	return 0;
}

