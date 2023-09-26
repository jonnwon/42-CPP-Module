#include "Span.hpp"
#include <stdexcept>

Span::Span()
{
	std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int N)
:_N(N), _index(0)
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
		_index = rhs._index;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}

void	Span::addNumber(int n)
{
	if (_index == _N)
		throw std::out_of_range("Error: Full numbers");
//		throw std::exception();		// full
	_v.push_back(n);
	_index++;
}
