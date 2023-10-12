#include "iter.hpp"

int main()
{
	char arr_char[3] = {'a', 'b', 'c'};
	iter(arr_char, sizeof(arr_char) / sizeof(char), print<char>);

	std::cout << std::endl << "---------------" << std::endl;

	int arr_int[3] = {1, 2, 3};
	iter(arr_int, sizeof(arr_int) / sizeof(int), print<int>);

	std::cout << std::endl << "---------------" << std::endl;

	std::string arr_str[3] = {"111", "222", "333"};
	iter(arr_str, sizeof(arr_str) / sizeof(std::string), print<std::string>);

	std::cout << std::endl << "---------------" << std::endl;
	
	double arr_double[3] = {1.111, 2.222, 3.333};
	iter(arr_double, sizeof(arr_double) / sizeof(double), print<double>);

	std::cout << std::endl << "---------------" << std::endl;
	
	float arr_float[3] = {1.111f, 2.222f, 3.333f};
	iter(arr_float, sizeof(arr_float) / sizeof(float), print<float>);

	
	std::cout << std::endl << "======const correctness======" << std::endl;

	const char arr_const_char[3] = {'a', 'b', 'c'};
	iter(arr_const_char, sizeof(arr_const_char) / sizeof(char), print<const char>);

	std::cout << std::endl << "---------------" << std::endl;

	const int arr_const_int[3] = {1, 2, 3};
	iter(arr_const_int, sizeof(arr_const_int) / sizeof(int), print<const int>);

	std::cout << std::endl << "---------------" << std::endl;

	const std::string arr_const_str[3] = {"111", "222", "333"};
	iter(arr_const_str, sizeof(arr_const_str) / sizeof(std::string), print<const std::string>);

	std::cout << std::endl << "---------------" << std::endl;
	
	const double arr_const_double[3] = {1.111, 2.222, 3.333};
	iter(arr_const_double, sizeof(arr_const_double) / sizeof(double), print<const double>);

	std::cout << std::endl << "---------------" << std::endl;
	
	const float arr_const_float[3] = {1.111f, 2.222f, 3.333f};
	iter(arr_const_float, sizeof(arr_float) / sizeof(float), print<const float>);

	return 0;
}
