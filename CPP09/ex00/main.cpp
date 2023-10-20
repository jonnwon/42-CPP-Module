#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : Need one argument" << std::endl;
		return 1;
	}
	BitcoinExchange a;

	std::string database = "data.csv";
	std::string inputFileName = static_cast<std::string>(argv[1]);

//	std::cout << "database: " << database << std::endl;
//	std::cout << "inputFileName : " << inputFileName << std::endl;

	try
	{
		a.readDatabase(database);
		//	a.printData();
		a.readInputFile(inputFileName);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
