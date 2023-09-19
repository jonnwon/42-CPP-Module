#include "ScalarConverter.hpp"
#include <iomanip>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Need one argument!" << std::endl;
		return (1);
	}
	ScalarConverter scalar(argv[1]);
	std::cout << scalar;

	return 0;
}
