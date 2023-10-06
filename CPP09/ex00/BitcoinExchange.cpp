#include "BitcoinExchange.hpp"
#include <cstddef>
#include <exception>
#include <iterator>
#include <sstream>
#include <string>
#include <sys/cdefs.h>
#include <variant>

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
		throw OpenFileException();
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date, delim, value;
		std::stringstream ss(line);
		ss >> date >> delim >> value;
	
		try
		{
			check_date(date);
			check_value(value);
			double rate = findRate();
			printData2(date, value, rate);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << " => " << line << std::endl;
		}
	}
}

void	BitcoinExchange::check_date(std::string &date)
{
	int tmp = 0;		// sum of '-' (should have 2)

	for (unsigned int i = 0; i < date.length(); i++)
	{
		if (date[i] == '-')
			tmp++;
		if (!isdigit(date[i]) && date[i] != '-')
			throw BadInputException();
	}
	if (tmp != 2)
		throw BadInputException();

	std::stringstream ss(date);
	std::string token;

	std::getline(ss, token, '-');
	_year = std::strtod(token.c_str(), NULL);

	std::getline(ss, token, '-');
	_month = std::strtod(token.c_str(), NULL);

	std::getline(ss, token, '-');
	_day = std::strtod(token.c_str(), NULL);

	if (_year < 2009 || _month < 1 || _month > 12)
		throw BadInputException();
	else if ((_month == 1 || _month == 3 || _month == 5 || _month == 7 || \
				_month == 8 || _month == 10 || _month == 12) && (_day < 1 || _day > 31))
		throw BadInputException();
	else if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && \
				(_day < 1 || _day > 30))
		throw BadInputException();
	else if (_month == 2 && (static_cast<int>(_year) % 4 == 0) && (_day < 1 || _day > 29))	// yoon neon;
		throw BadInputException();
	else if (_month == 2 && (static_cast<int>(_year) % 4 != 0 && (_day < 1 || _day > 28)))
		throw BadInputException();
}

void	BitcoinExchange::check_value(std::string &value)
{
	int tmp = 0;		// sum of '-' (should have 2)

	if (value[0] == '-')
		throw NotPositiveException();
	for (unsigned int i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
			tmp++;
		if (!isdigit(value[i]) && value[i] != '.')
			throw BadInputException();
	}
	if (tmp > 1)
		throw BadInputException();

	double _dValue = std::strtod(value.c_str(), NULL);
	if (_dValue > 1000)
		throw TooLargeException();
}

double	BitcoinExchange::findRate()
{
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		if (compDate(it->first))
		{
			it--;
//			std::cout << "test: " << it->second << std::endl;
			return it->second;
//			break ;
		}
	}

	std::map<std::string, double>::iterator it = _data.end();
	it--;
	if (!compDate(it->first))
	{
//		std::cout << "test2: " << _data.end()->second << std::endl;
		return it->second;
	}

	return 0;
}

bool	BitcoinExchange::compDate(const std::string& first)		// if lastly == true 
{
	std::stringstream ss(first);
	std::string token;
	double year, month, day;

	std::getline(ss, token, '-');
	year = std::strtod(token.c_str(), NULL);

	std::getline(ss, token, '-');
	month = std::strtod(token.c_str(), NULL);

	std::getline(ss, token);
	day = std::strtod(token.c_str(), NULL);

//	std::cout << "year : " << year << std::endl;
//	std::cout << "month : " << month << std::endl;
//	std::cout << "day : " << day << std::endl;
//

//	std::cout << "_year : " << _year << std::endl;
//	std::cout << "year : " << year << std::endl;

	if (_year < year)
	{
		return true;
	}
	else if (_year == year)
	{
		if (_month < month)
			return true;
		else if (_month == month)
		{
			if (_day < day)
				return true;
			else
				return false;
		}
		else if (_month > month)
			return false;
	}
	return false;	// _year > year 
}

const char* BitcoinExchange::OpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	return "Error: bad input";
}

const char* BitcoinExchange::TooLargeException::what() const throw()
{
	return "Error: too large a number.";
}

const char* BitcoinExchange::NotPositiveException::what() const throw()
{
	return "Error: not a positive number.";
}

//const char* BitcoinExchange::InvalidInputException::what() const throw()
//{
//	return "Error: invalid input.";
//}
//
