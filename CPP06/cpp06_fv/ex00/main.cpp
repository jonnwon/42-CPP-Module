#include "ScalarConverter.hpp"

void	checkLiteral(std::string& str)
{
	int idx = -1;

	bool (*p[4])(std::string& str) = {&ScalarConverter::isCharLiteral, &ScalarConverter::isIntLiteral\
		, &ScalarConverter::isFloatLiteral, &ScalarConverter::isDoubleLiteral};

	for (int i = 0; i < 4; i++)
	{
		if (p[i](str) == true)
		{
			idx = i;
			break ;
		}
	}
	switch (idx)
	{
		case -1:
			std::cout << "Invalid Literal" << std::endl;
			break;
		case 0:
			std::cout << "Char Literal" << std::endl;
			break;
		case 1:
			std::cout << "Int Literal" << std::endl;
			break;
		case 2:
			std::cout << "Float Literal" << std::endl;
			break;
		case 3:
			std::cout << "Double Literal" << std::endl;
			break;
	}
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
