#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

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

		std::vector<size_t> insertionOrder;


	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		template <typename T>
		void	printStl(T &t)
		{
			typename T::iterator it;
			typename T::iterator ite = t.end();

			for (it = t.begin(); it != ite; ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		void	parseInput(char **input);

		template <typename T>
		void swap(T& a, T& b)
		{
			T temp = a;
			a = b;
			b = temp;
		}


		void	init_vector_and_deque();

		void	initVector();
		void	initDeque();


		size_t	jacobsthal(int n);
		void	initInsertionOrder(size_t size);

		void	insertionVector();
		void	insertionDeque();

		class	InputException : public std::exception
		{
			public:
				virtual	const char * what() const throw();
		};

};

#endif
