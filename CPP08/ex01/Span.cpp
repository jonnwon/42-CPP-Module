#include "Span.hpp"
#include <exception>
#include <numeric>
#include <random>
#include <vector>

Span::Span()
{
}

Span::Span(unsigned int N)
:_N(N), _index(0)
{
}

Span::Span(const Span& other)
{
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
}

void	Span::addNumber(int n)
{
	if (_index == _N)
		throw NoSpaceException();
	_v.push_back(n);
	_index++;
}

//void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
//{
//    for (std::vector<int>::iterator it = begin; it != end; it++)
//    {
//        addNumber(*it);
//    }
//}

//int	Span::shortestSpan()
//{
//	int min;
//
//	if (_index < 2)
//		throw NotEnoughNumbersException();
//	std::vector<int> v = _v;
//	std::sort(v.begin(), v.end());
//
//	min = v[1] - v[0];
//	for (unsigned int i = 1; i < _N; i++)
//	{
//		if (v[i + 1] && v[i + 1] - v[i] < min)
//			min = v[i + 1] - v[i]; 
//	}
//	return min;
//}

int	Span::shortestSpan()
{
	int	min;

	if (_index < 2)
		throw NotEnoughNumbersException();

	std::vector<int> v(_index);
	std::vector<int>::iterator it;

	it = std::adjacent_difference(_v.begin(), _v.end(), v.begin());

	if (v[1] < 0)
		v[1] *= -1;
	min = v[1];

	for (std::vector<int>::size_type i = 1; i < v.size(); i++)
	{
		if (v[i] < 0)
			v[i] *= -1;
		if (min > v[i])
			min = v[i];
	}
	return min;
}

int	Span::longestSpan()
{
	int max;

	if (_index < 2)
		throw NotEnoughNumbersException();

	std::vector<int> v(_index);
	std::vector<int>::iterator it;

	it = std::adjacent_difference(_v.begin(), _v.end(), v.begin());

	if (v[1] < 0)
		v[1] *= -1;
	max = v[1];
	
	for (std::vector<int>::size_type i = 1; i < v.size(); i++)
	{
		if (v[i] < 0)
			v[i] *= -1;
		if (max < v[i])
			max = v[i];
	}
	return max;
}

//int Span::longestSpan()
//{
//	if (_index < 2)
//		throw NotEnoughNumbersException();
//	int min_value = *std::min_element(_v.begin(), _v.end());
//	int max_value = *std::max_element(_v.begin(), _v.end());
//	
//	return max_value - min_value;
//}


void	Span::print_info()
{
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Span capacity: " << _N << std::endl;
	std::cout << "index: " << _index << std::endl;
}

const char* Span::NoSpaceException::what() const throw()
{
	return "No more numbers can be added !";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers";
}
