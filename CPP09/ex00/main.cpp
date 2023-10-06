#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <sstream>

int main()
{
	std::string filename = "input.txt";

	std::ifstream file;

	file.open(filename);
	if (!file.is_open())
	{
		std::cout << "file open error!" << std::endl;
		return 1;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		// 날짜와 숫자를 분리합니다.
		std::string date, delim, value;
		std::stringstream ss(line);
		ss >> date >> delim >> value;

//		std::cout << "data: " << date << std::endl;
//		std::cout << "value: " << value << std::endl;
//		std::cout << date << delim << value << std::endl;
		double num = std::strtod(value.c_str(), NULL);
//		std::cout << std::fixed << std::setprecision(3) << num << std::endl;
		std::cout << std::fixed << num << std::endl;
	}
	file.close();

	return 0;
}

/*
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : Need one argument" << std::endl;
		return 1;
	}
	BitcoinExchange a;
	std::string data = "data.csv";
//	std::string	inputfile = "input.txt";
	std::string	inputfile = static_cast<std::string>(argv[1]);

	try
	{
		a.readDatabase(data);
		a.readInputfile(inputfile);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
*/
