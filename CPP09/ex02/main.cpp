#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	clock_t	start, end;
	double elapsed_time;

	(void)argc;

	PmergeMe a;

	try
	{
		a.parseInput(argv);


		start = clock();
		a.initVector();
		a.insertionVector();
		end = clock();
		
		elapsed_time = double(end - start) / CLOCKS_PER_SEC;

		std::cout << "time: " << std::fixed << elapsed_time << std::endl;

		start = clock();
		a.initDeque();
		a.insertionDeque();
		end = clock();

		elapsed_time = double(end - start) / CLOCKS_PER_SEC;

		std::cout << "time: " << std::fixed << elapsed_time << std::endl;


		start = clock();
		a.initDeque();
		a.insertionDeque_2();
		end = clock();

		elapsed_time = double(end - start) / CLOCKS_PER_SEC;

		std::cout << "time: " << std::fixed << elapsed_time << std::endl;



	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
