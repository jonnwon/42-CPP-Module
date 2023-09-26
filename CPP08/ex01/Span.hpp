#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int _N;
		unsigned int _index;
		Span();

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& rhs);
		~Span();

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
		void	print_info();

		class NoSpaceException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
