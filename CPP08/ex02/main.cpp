#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "=============" << std::endl;
	std::cout << "Compare with list" << std::endl;
	std::cout << "mstack size: " << mstack.size() << std::endl;
	std::cout << "mstack contents" << std::endl;

	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}

	std::cout << std::endl << "-----------" << std::endl;

	std::list<int> list;

	list.push_back(5);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << "list size: " << list.size() << std::endl;
	std::cout << "list contents" << std::endl;

	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "=============" << std::endl;
	std::cout << "Copy constructor test" << std::endl;
	{
		MutantStack<int> copy(mstack);

		std::cout << "Print copy" << std::endl;

		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); it++)
		{
			std::cout << *it << " ";
		}
	}

	std::cout << std::endl << "=============" << std::endl;
	std::cout << "Copy assignment operator test" << std::endl;
	{
		MutantStack<int> copy;

		copy = mstack;
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); it++)
		{
			std::cout << *it << " ";
		}
	}

	return 0;
}
