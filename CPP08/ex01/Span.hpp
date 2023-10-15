#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
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

		// template 으로 다시 구현 
//		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		template <typename InputIt>
		void	addRange(InputIt first, InputIt last)
		{
//			std::cout << "first: " << *first << std::endl;
//			std::cout << "first: " << *(first + 1) << std::endl;
//			std::cout << "last: " << *(last - 1) << std::endl;

			for (InputIt it = first; it != last; ++it)
			{
				if (_index == _N)
					throw NoSpaceException();
				_v.push_back(*it);
				_index++;
				//std::cout << *it << std::endl;
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
