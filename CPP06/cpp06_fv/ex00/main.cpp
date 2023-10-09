#include "ScalarConverter.hpp"

void	checkLiteral(std::string& str)
{
	std::cout << "str: " << str << std::endl;
	std::cout << "isCharLiteral: " << ScalarConverter::isCharLiteral(str) << std::endl;
	std::cout << "isIntLiteral: " << ScalarConverter::isIntLiteral(str) << std::endl;


	std::cout << "IsFloatLiteral: " << ScalarConverter::isFloatLiteral(str) << std::endl;

	std::cout << "IsDoubleLiteral: " << ScalarConverter::isDoubleLiteral(str) << std::endl;

}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Need one argument" << std::endl;
		return (1);
	}

	std::string str(argv[1]);

//	checkLiteral(str);

	ScalarConverter::convert(str);

	return 0;
}
