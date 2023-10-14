#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

class NotFoundException : public std::exception
{
    virtual const char* what() const throw()
    {
		return "Element not found";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw NotFoundException();
	std::cout << "Element found" << std::endl;
	return it;
}

#endif
