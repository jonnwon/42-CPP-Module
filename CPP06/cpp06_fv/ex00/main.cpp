#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Need one argument" << std::endl;
		return (1);
	}

	std::string literal(argv[1]);

	double *_dValue = NULL;

//	_dValue = new double(std::stod(literal, NULL));

//	std::cout << *_dValue << std::endl;
//	std::cout << _dValue << std::endl;

	try
	{
	std::cout << ScalarConverter::toInt(_dValue) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		_dValue = new double(std::stod(literal, NULL));
	}
	std::cout << *_dValue << std::endl;

	return 0;
}
