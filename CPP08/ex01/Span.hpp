#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int _N;
		unsigned int _index;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& rhs);
		~Span();

		void addNumber(int n);
//		void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
//		int	shortesSpan();
//		int longestSpan();
		
		unsigned int getN() const
		{
			return _N;
		}
		
		void	print_info()
		{
			for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;

			std::cout << "_N: " << _N << std::endl;
			std::cout <<"_indxe: " << _index << std::endl;

		}

		void	print_index()
		{
			std::cout << "_index: " << _index << std::endl;
		}
		
		void	replaceNumber()
		{
			std::replace(_v.begin(), _v.end(), 1, 10000);
		}


		std::vector<int>::iterator getBegin()
		{
			return _v.begin();
		}

		std::vector<int>::iterator getEnd()
		{
			return _v.end();
		}

};

#endif
