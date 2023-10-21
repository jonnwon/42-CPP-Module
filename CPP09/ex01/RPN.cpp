#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& rhs)
{
	(void)rhs;
	return *this;
}

RPN::~RPN()
{
}

void	RPN::checkInput(const char *input)
{
	std::string str(input);
	std::istringstream ss(str);
    std::string token;
	int			sum_of_num = 0;
	int			sum_of_operator = 0;

	while (ss >> token)
	{
		if (token.length() > 1)
		{
			std::cout << token<< ": Too long" << std::endl;
			throw InputException();
		}
		if (!isdigit(static_cast<int>(token[0])) || token[0] != '+' || token[0] != '-' || token[0] != '*' || token[0] != '/')
		{ 
			std::cout << token <<": not digit" << std::endl;
			throw InputException();
		}
		if (isdigit(token[0]))
			sum_of_num++;
		else
			sum_of_operator++;
	}
	if (sum_of_num - 1 != sum_of_operator)
	{
		std::cout << "sum Error" << std::endl;
		throw InputException();
	}


}

const char * RPN::InputException::what() const throw()
{
	return "Error: input error";
}
