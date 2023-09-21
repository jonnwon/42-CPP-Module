#include "iter.hpp"

int main()
{
	int arr_int[3] = {1, 2, 3};
	iter(arr_int, sizeof(arr_int) / sizeof(int), print<int>);

	std::cout << std::endl << "---------------" << std::endl;

	std::string arr_str[3] = {"111", "222", "333"};
	iter(arr_str, sizeof(arr_str) / sizeof(std::string), print);

	std::cout << std::endl << "---------------" << std::endl;
	
	double arr_double[3] = {1.111, 2.222, 3.333};
	iter(arr_double, sizeof(arr_double) / sizeof(double), print);

	return 0;
}
