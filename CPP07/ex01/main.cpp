#include "iter.hpp"

int main()
{
	char arr_char[3] = {'a', 'b', 'c'};
	iter(arr_char, sizeof(arr_char) / sizeof(char), print<char>);

	std::cout << std::endl << "---------------" << std::endl;

	int arr_int[3] = {1, 2, 3};
	iter(arr_int, sizeof(arr_int) / sizeof(int), print<int>);

	
	std::cout << std::endl << "======const correctness======" << std::endl;

	const char arr_const_char[3] = {'a', 'b', 'c'};
	iter(arr_const_char, sizeof(arr_const_char) / sizeof(char), print<const char>);

	std::cout << std::endl << "---------------" << std::endl;

	const int arr_const_int[3] = {1, 2, 3};
	iter(arr_const_int, sizeof(arr_const_int) / sizeof(int), print<const int>);

	return 0;
}
