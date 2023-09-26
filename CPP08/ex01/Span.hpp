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
		int	shortesSpan();
		int longestSpan();
		

};


#endif
