#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Need one argument" << std::endl;
		return 1;
	}

	try
	{
	
	RPN::printTest();
	RPN::checkInput(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

