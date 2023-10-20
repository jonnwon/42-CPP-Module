#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iomanip>
#include <ios>
#include <sstream>

//int main()
//{
//	std::string filename = "input.txt";
//
//	std::ifstream file;
//
//	file.open(filename);
//	if (!file.is_open())
//	{
//		std::cout << "file open error!" << std::endl;
//		return 1;
//	}
//
//	std::string line;
//	std::getline(file, line);
//	while (std::getline(file, line))
//	{
//		// 날짜와 숫자를 분리합니다.
//		std::string date, delim, value;
//		std::stringstream ss(line);
//		ss >> date >> delim >> value;
//
//		double	num = std::strtod(value.c_str(), NULL);
//
//		std::cout << date << delim << std::fixed << num << std::endl; 
//		std::stringstream ss_date(date);
//		std::string token;
//		while(std::getline(ss_date, token, '-'))
//		{
//			double tmp = std::strtod(token.c_str(), NULL); 
//			std::cout << std::fixed << std::setprecision(0) << tmp << std::endl;
//		}
//
//	}
//	file.close();
//
//	return 0;
//}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : Need one argument" << std::endl;
		return 1;
	}
	BitcoinExchange a;
	std::string data = "data.csv";
	std::string	inputfile = static_cast<std::string>(argv[1]);

	try
	{
		a.readDatabase(data);
		a.printData();
//		a.readInputfile(inputfile);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}


