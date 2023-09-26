#include "Span.hpp"

Span::Span()
{
	std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int N)
:_N(N)
{
	std::cout << "Constructor called" << std::endl;
}

Span::Span(const Span& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_v = rhs._v;
		_N = rhs._N;
		//_index = rhs._index;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}

void	Span::addNumber(int n)
{
	_v.push_back(n);
}
