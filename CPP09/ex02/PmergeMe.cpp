#include "PmergeMe.hpp"
#include <algorithm>
#include <sstream>
#include <vector>

PmergeMe::PmergeMe()
{
}
		
PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		//
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::parseInput(char **input)
{
	for (int i = 1; input[i]; i++)
	{
		for (int j = 0; input[i][j]; j++)
		{
			if (!isdigit(input[i][j]))
				throw InputException();
		}
		std::string str(input[i]);
		std::istringstream ss(str);
		long long num;

		ss >> num;
		
		unsorted.push_back(num);
	}
	
	if (unsorted.size() % 2 != 0)
	{
		isOdd = true;
		lastNumber = unsorted.back();
		unsorted.pop_back();
	}
	else
		isOdd = false;

//	std::cout << " -- unsorted -- "  << std::endl;
//	printStl(unsorted);

	//  initInsertionOrder
	int size;
	if (isOdd)
		size = unsorted.size() / 2 + 1;
	else
		size = (unsorted.size() / 2);
	initInsertionOrder(size);

//	std::cout << "-- insertionOrder --" << std::endl;
//	printStl(insertionOrder);
}


size_t	PmergeMe::jacobsthal(int n)
{
    if (n == 0) 
        return 0;
    else if (n == 1)
        return 1;
    else
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


void	PmergeMe::initInsertionOrder(size_t size)
{
	insertionOrder.push_back(1);
	for (size_t i = 3; jacobsthal(i) <= size; i++)
	{
		for (size_t num = jacobsthal(i); num != jacobsthal(i - 1); num--)
		{
			insertionOrder.push_back(num);
		}
	}

	int num = size;
	while (insertionOrder.size() != size)
	{
		insertionOrder.push_back(num);
		num--;
	}
}

void	PmergeMe::initVector()
{
	for (size_t i = 0; i < unsorted.size(); i += 2)
	{
		long long left = unsorted[i];
		long long right = unsorted[i + 1];

		if (left < right)
			swap(left, right);
		vMain.push_back(left);
		vPending.push_back(right);
	}

	for (size_t i = 0; i < vMain.size(); i++)
	{
		for (size_t j = i + 1; j < vMain.size(); j++)
		{
			if (vMain[i] > vMain[j])
			{
				swap(vMain[i], vMain[j]);
				swap(vPending[i], vPending[j]);
			}
		}
	}
	if (isOdd)
		vPending.push_back(lastNumber);

//	std::cout << "-- vMain --" << std::endl;
//	printStl(vMain);
//
//	std::cout << "-- vPending --" << std::endl;
//	printStl(vPending);
}

void	PmergeMe::initDeque()
{
	for (size_t i = 0; i < unsorted.size(); i += 2)
	{
		long long left = unsorted[i];
		long long right = unsorted[i + 1];

		if (left < right)
			swap(left, right);
		dMain.push_back(left);
		dPending.push_back(right);
	}

	for (size_t i = 0; i < dMain.size(); i++)
	{
		for (size_t j = i + 1; j < dMain.size(); j++)
		{
			if (dMain[i] > dMain[j])
			{
				swap(dMain[i], dMain[j]);
				swap(dPending[i], dPending[j]);
			}
		}
	}
	if (isOdd)
		dPending.push_back(lastNumber);

//	std::cout << "-- dMain --" << std::endl;
//	printStl(dMain);
//
//	std::cout << "-- dPending --" << std::endl;
//	printStl(dPending);
}


void	PmergeMe::insertionVector()
{
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		std::vector<long long>::iterator it;
		std::vector<long long>::iterator end = vMain.begin() + insertionOrder[i] - 1;

		it = std::upper_bound(vMain.begin(), end, vPending[insertionOrder[i] - 1]);
		vMain.insert(it, vPending[insertionOrder[i] - 1]);
	}
//	printStl(vMain);
}

void	PmergeMe::insertionDeque()
{
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		std::deque<long long>::iterator it;
		std::deque<long long>::iterator end = dMain.begin() + insertionOrder[i] - 1;

		it = std::upper_bound(dMain.begin(), end, dPending[insertionOrder[i] - 1]);
		dMain.insert(it, dPending[insertionOrder[i] - 1]);
	}
//	printStl(dMain);
}

const char * PmergeMe::InputException::what() const throw()
{
	return "Error: not digit";
}
