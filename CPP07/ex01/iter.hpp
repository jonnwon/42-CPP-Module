#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename U>
void	iter(T	*arr, size_t len, U (*f)(T &))
{
	if (arr == NULL || f == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T, typename U>
void	iter(const T *arr, size_t len, U (*f)(const T &))
{
	if (arr == NULL || f == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void print(T& element)
{
	std::cout << element << " ";
}

#endif

