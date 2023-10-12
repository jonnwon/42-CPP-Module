#include "Array.hpp"

#define MAX_VAL 750

void	empty_array_test()
{
	std::cout << "Empty Array test" << std::endl;
	{
		try
		{
			Array<int> arr;
			for (int i = 0; i < 10; i++)
				arr[i] = i;		// throw exception
			std::cout << arr;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "===================" << std::endl;
}

void	array_int_test()
{
	std::cout << "n Array<int> test" << std::endl;
	{
		try
		{
			Array<int> arr(10);
			std::cout << "size: " << arr.size() << std::endl;
			for (int i = 0; i < 10; i++)
				arr[i] = i;
			std::cout << arr;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "===================" << std::endl;
}

void	arr_string_test()
{
	std::cout << "n Array<string> test" << std::endl;
	{
		try
		{
			Array<std::string> arr(10);
			std::cout << "size: " << arr.size() << std::endl;
			for (int i = 0; i < 10; i++)
				arr[i] = i + 65;
			std::cout << arr;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "===================" << std::endl;
}

void	copy_constructor_test()
{
	std::cout << "Copy constructor test" << std::endl;
	{
		try
		{
			Array<std::string> origin(10);
			for (int i = 0; i < 10; i++)
				origin[i] = i + 65;
			std::cout << origin;

			Array<std::string> copy(origin);
			std::cout << copy;

			origin[0] = 66;

			std::cout << "Print origin array" << std::endl;
			std::cout << origin;
			std::cout << "--------" << std::endl;
			std::cout << "Print copy array" << std::endl;
			std::cout << copy;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "===================" << std::endl;
}

void	copy_assignment_operator_test()
{
	std::cout << "Copy assignment operator test" << std::endl;
	{
		try
		{
			Array<int> arr1(10);
			for (int i = 0; i < 10; i++)
				arr1[i] = i + 10;
			std::cout << "Print arr1" << std::endl;
			std::cout << arr1;

			Array<int> arr2(10);
			for (int i = 0; i < 10; i++)
				arr2[i] = i;
			std::cout << "Print arr2" << std::endl;
			std::cout << arr2;


			arr1 = arr2;

			std::cout << "Print arr1 after assignment operator" << std::endl;
			std::cout << arr1;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "===================" << std::endl;
}

void	wrong_index_test()
{
	std::cout << "Wrong index test" << std::endl;
	{
		try
		{
			Array<int> arr(10);
			for (int i = 0; i < 10; i++)
				arr[i] = i;
			std::cout << arr[10];		// throw exception
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

int main()
{
	empty_array_test();
	array_int_test();
	arr_string_test();
	copy_constructor_test();
	copy_assignment_operator_test();
	wrong_index_test();

	// subject test
	
//	Array<int> numbers(MAX_VAL);
//	int* mirror = new int[MAX_VAL];
//	srand(time(NULL));
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		const int value = rand();
//		numbers[i] = value;
//		mirror[i] = value;
//	}
//	//SCOPE
//	{
//		Array<int> tmp = numbers;
//		Array<int> test(tmp);
//	}
//
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		if (mirror[i] != numbers[i])
//		{
//			std::cerr << "didn't save the same value!!" << std::endl;
//			return 1;
//		}
//	}
//	try
//	{
//		numbers[-2] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//	try
//	{
//		numbers[MAX_VAL] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		numbers[i] = rand();
//	}
//	delete [] mirror;

	return 0;
}
