#include "BitcoinExchange.hpp"
#include <string>

BitcoinExchange::BitcoinExchange()
{
	std::cout << "[BitcoinExchange] : Defualt constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	std::cout << "[BitcoinExchange] : Copy constructor called" << std::endl;
	
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	std::cout << "[BitcoinExchange] : Copy assignment operator called" << std::endl;

	if (this != &rhs)
		_data = rhs._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "[BitcoinExchange] : Destructor called" << std::endl;
}

void	BitcoinExchange::readDatabase(std::string &database)
{
	std::ifstream	file;
	std::string		line;
	std::string		key;
	double			value;

	file.open(database.c_str());
	if (!file.is_open())
	{
		std::cout << "file open error!" << std::endl;
		return ;
	}
	std::getline(file, line);
	while (!file.eof())
//	for (int i = 0; i < 1; i++)
	{
		std::getline(file, line, ',');
		key = line;
		std::getline(file, line, '\n');
		value = std::strtod(line.c_str(), NULL);
		_data[key] = value;
	}
	file.close();
}

void	BitcoinExchange::printData()
{
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << "data: " << it->first << ", rate: " << it->second << std::endl;
	}
}

void	BitcoinExchange::readInputfile(std::string &inputfile)
{
	std::ifstream	file;
	std::string		line;

	file.open(inputfile.c_str());
	if (!file.is_open())
		throw OpenFileExecption();
	std::getline(file, line);
	while (!file.eof())
	{
		std::getline(file, line, '|');
		std::cout << "date: " << line << std::endl;

		std::getline(file, line, '\n');
		std::cout << "number: " << line << std::endl;
	}
}

const char* BitcoinExchange::OpenFileExecption::what() const throw()
{
	return "Error : open file";
}
