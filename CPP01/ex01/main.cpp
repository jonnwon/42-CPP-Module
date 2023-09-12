#include "Zombie.hpp"

int main()
{
	Zombie	stack;
	Zombie	*heap;
	int		N;

	std::cout << "Please enter the number of zombies: ";
	std::cin >> N;

	heap = zombieHorde(N, "Heap");
	for (int i = 0; i < N; i++)
	{
		heap[i].announce();
	}
	delete[] heap;

	system("leaks Moar_brainz");	//leak test
	return (0);
}
