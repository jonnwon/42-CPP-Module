#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void)argc;

	PmergeMe a;

	try
	{
		a.parseInput(argv);
		a.initVector();
		a.insertionVector();

		a.initDeque();
		a.insertionDeque();

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
