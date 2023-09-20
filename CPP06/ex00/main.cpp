#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Need one argument!" << std::endl;
		return (1);
	}
	double _dValue = std::atof(static_cast<std::string>(argv[1]).c_str());
	ScalarConverter::conversion(_dValue);
	return 0;
}
