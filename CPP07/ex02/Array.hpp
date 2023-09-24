#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T				*_arr;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& rhs);
		~Array();

		T& operator[](unsigned int index) const;
		unsigned int size() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& outputStream, const Array<T>& rhs)
{
	for (unsigned int i = 0; i < rhs.size(); i++)
	{
		outputStream << rhs[i] << std::endl;
	}
	return outputStream;
}

template <typename T>
Array<T>::Array()
:_size(0)
{
	std::cout << "[Array<T>] : Default constructor called" << std::endl;
	_arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
:_size(n)
{
	std::cout << "[Array<T>] : Constructor called" << std::endl;
	_arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
:_size(other._size)
{
	std::cout << "[Array<T>] : Copy constructor called" << std::endl;
	_arr = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
		_arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	std::cout << "[Array<T>] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		delete[] _arr;
		_arr = new T[rhs._size];
		_size = rhs._size;
		for (unsigned int i = 0; i < rhs._size; i++)
			_arr[i] = rhs._arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "[Array<T>] : Destructor called" << std::endl;
	delete[] _arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index < 0 || index >= _size)
	{
		throw std::out_of_range("Array index out of bounds");
	}
	return _arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
