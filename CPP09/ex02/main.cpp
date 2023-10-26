#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	clock_t	start, end;
	double elapsed_time;

	if (argc < 2)
	{
		std::cout << "Error: need argument" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe a;
		a.parseInput(argv);

	

		start = clock();
		a.initVector();
		a.insertionVector();
		end = clock();
		
		elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "vector time: " << std::fixed << elapsed_time << std::endl;

		start = clock();
		a.initDeque();
		a.insertionDeque();
		end = clock();

		elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "deque time: " << std::fixed << elapsed_time << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
