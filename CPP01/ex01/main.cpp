#include "Zombie.hpp"

int main()
{
	Zombie	stack;
	Zombie	*heap;
	int		N = 3;

	stack.set_name("Stack");
	heap = zombieHorde(N, "Heap");
	stack.announce();
	for (int i = 0; i < N; i++)
	{
		heap[i].announce();
	}
	delete[] heap;
	return (0);
}
