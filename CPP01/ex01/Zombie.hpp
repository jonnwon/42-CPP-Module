#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
		int index;

	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	set_name(std::string name);
		void	set_index(int index);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
