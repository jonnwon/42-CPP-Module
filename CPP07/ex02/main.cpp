#include "Array.hpp"

int main()
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
	std::cout << "n Array<int> test" << std::endl;
	{
		try
		{
			Array<int> arr(10);
			for (int i = 0; i < 10; i++)
				arr[i] = i;
			std::cout << arr;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "===================" << std::endl;
	std::cout << "n Array<string> test" << std::endl;
	{
		try
		{
			Array<std::string> arr(10);
			for (int i = 0; i < 10; i++)
				arr[i] = i + 65;
			std::cout << arr;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "===================" << std::endl;
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

	return 0;
}
