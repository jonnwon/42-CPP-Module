#include "easyfind.hpp"

int main()
{
	std::cout << "=======vector test =======" << std::endl;

	std::vector<int> v;

	for (int i = 0; i < 5; i++)
		v.push_back(i);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 1);
		std::cout << "value: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------" << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(v, 10);
		std::cout << "value: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "=======list test =======" << std::endl;

	std::list<int> l;
	for (int i = 0; i < 5; i++)
		l.push_back(i);

	try
	{
		std::list<int>::iterator it2 = easyfind(l, 1);
		std::cout << "value: " << *it2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------" << std::endl;

	try
	{
		std::list<int>::iterator it2 = easyfind(l, 10);
		std::cout << "value: " << *it2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "=======deque test =======" << std::endl;
	
	std::deque<int> d;
	for (int i = 0; i < 5; i++)
		d.push_back(i);

	try
	{
		std::deque<int>::iterator it3 = easyfind(d, 1);
		std::cout << "value: " << *it3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------" << std::endl;

	try
	{
		std::deque<int>::iterator it3 = easyfind(d, 10);
		std::cout << "value: " << *it3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
