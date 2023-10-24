#include "RPN.hpp"
#include <cwchar>
#include <exception>
#include <type_traits>

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

void	RPN::parseInput(const char *input)
{
	std::string			str(input);		// "asd 123 asd
	std::istringstream	ss(str);
    std::string			token;
	std::stack<double>	stack;
	double				result;

	while (ss >> token)
	{
		if (token.length() > 1)
			throw InputException();
		if (!isdigit((token[0])) && token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/')
			throw InputException();
		if (isdigit(token[0]))
			stack.push(static_cast<int>(token[0]) - 48);
		else
		{
			result = calculate(stack, token[0]);
			stack.push(result);
		}
	}
	if (stack.size() != 1)
		throw InputException();
	std::cout << result << std::endl;
}

double	RPN::calculate(std::stack<double> &stack, char &op)
{
	int		idx;
	double	result = 0;
	double	first;
	double	second;

	char	operators[4] = {'+', '-', '*', '/'};

	for (int i = 0; i < 4; i++)
	{
		if (op == operators[i])
			idx = i;
	}

	if (!stack.empty())
	{
		first = stack.top();
		stack.pop();
	}
	else
		throw InputException();

	if (!stack.empty())
	{
		second = stack.top();
		stack.pop();
	}
	else
		throw InputException();

	switch (idx)
	{
		case 0:
			result = second + first;
			break;
		case 1:
			result = second - first;
			break;
		case 2:
			result = second * first;
			break;
		case 3:
			result = second / first;
			break;
	}
	return result;
}

const char * RPN::InputException::what() const throw()
{
	return "Error";
}
