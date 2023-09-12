#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		club.setType("some other type of club");
		jim.attack();
	}

//<<<<<<< HEAD
//	//system("leaks Unnecessary_violence");		// leak test
//=======
//	system("leaks Unnecessary_violence");	// leak check
//>>>>>>> 922b1e04a17e33f127bdb0d7e4e63d5dacdc078e
	return 0;
}
