#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>

class PmergeMe
{
	private:
		std::vector<long long>	unsorted;
		bool					isOdd;
		long long				lastNumber;
		

		std::vector<long long> sorted;

		std::vector<long long> vMain;
		std::vector<long long> vPending;

		std::deque<long long> dMain;
		std::deque<long long> dPending;

		std::list<long long> lMain;
		std::list<long long> lPending;


		std::vector<size_t> insertionOrder;


	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void	parseInput(char **input);

		size_t	jacobsthal(int n);
		void	initInsertionOrder(size_t size);

		void	initVector();
		void	initDeque();

		void	insertionVector();
		void	insertionDeque();

		void	insertionDeque_2();

		class	InputException : public std::exception
		{
			public:
				virtual	const char * what() const throw();
		};

};

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void	printStl(T &t)
{
	typename T::iterator it;
	typename T::iterator ite = t.end();

	for (it = t.begin(); it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif
