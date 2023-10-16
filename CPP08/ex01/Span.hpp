#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>
#include <numeric>

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

		template <typename InputIt>
		void	addRange(InputIt first, InputIt last)
		{
			for (InputIt it = first; it != last; ++it)
			{
				if (_index == _N)
					throw NoSpaceException();
				_v.push_back(*it);
				_index++;
			}
		}

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
