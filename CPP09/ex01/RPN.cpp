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

	while (ss >> token)
	{
		std::cout << "token: " << token << std::endl;
		std::cout << "token's length: " << token.length() << std::endl;
	}

}
