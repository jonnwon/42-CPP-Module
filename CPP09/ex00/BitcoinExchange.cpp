#include "BitcoinExchange.hpp"

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
	{
		_data = rhs._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "[BitcoinExchange] : Destructor called" << std::endl;
}

void	BitcoinExchange::readDatabase(std::string& database)
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
		key = line;									// get key (string)
		std::getline(file, line, '\n');				// get value (string)
		value = std::strtod(line.c_str(), NULL);	// type change of value (string to double)
		_data[key] = value;							// save key and value to map
	}
	file.close();
}

void	BitcoinExchange::printData()
{
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << "data: " << it->first << " | rate: " << it->second << std::endl;
	}
}

void	BitcoinExchange::readInputFile(std::string &inputFile)
{
	std::ifstream	file;
	std::string		line;

	file.open(inputFile.c_str());
	if (!file.is_open())
	{
		throw OpenFileException();
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date, delim, value;
		std::stringstream ss(line);
		ss >> date >> delim >> value;
	
		// Test
		try
		{
			// date == "" || delim == "" || value == "" 
			if (date.compare("") == 0 || delim.compare("") == 0 || value.compare("") == 0)
				throw InputException();
			else if (delim.compare("|") != 0)
				throw DelimException();
			checkDate(date);
			checkValue(value);
			double rate = findRate();
			printResult(date, value, rate);
		}
		catch (BitcoinExchange::InputException &e)	// InputException
		{
			std::cout << e.what() << " => " << line << std::endl;
		}
		catch (BitcoinExchange::DelimException &e)
		{
			std::cout << e.what() << " => " << delim << std::endl;
		}
		catch (BitcoinExchange::DateException &e)
		{
			std::cout << e.what() << " => " << date << std::endl;
		}
		catch (BitcoinExchange::NotPositiveException &e)
		{
			std::cout << e.what() << " -> " << value << std::endl;
		}
		catch (BitcoinExchange::ValueException &e)
		{
			std::cout << e.what() << " -> " << value << std::endl;
		}
		catch (BitcoinExchange::TooLargeException &e)
		{
			std::cout << e.what() << " -> " << value << std::endl;
		}
	}
}

void	BitcoinExchange::checkDate(std::string &date)
{
	int	sum_of_dash = 0;

	for (unsigned int i = 0; i < date.length(); i++)
	{
		if (date[i] == '-')								// count '-'
			sum_of_dash++;
		if (!isdigit(date[i]) && date[i] != '-')		// check number or '-'
			throw DateException();
	}
	if (sum_of_dash != 2)
		throw DateException();

	std::stringstream ss(date);
	std::string token;

	std::getline(ss, token, '-');
	_year = static_cast<int>(std::strtod(token.c_str(), NULL));

	std::getline(ss, token, '-');
	_month = static_cast<int>(std::strtod(token.c_str(), NULL));

	std::getline(ss, token, '\n');
	_day = static_cast<int>(std::strtod(token.c_str(), NULL));

//	std::cout << _year << "-" << _month << "-" << _day << std::endl;		// delete

	// under 2009, month 1~12
	if (_year < 2009 || _month < 1 || _month > 12 || \
		(_year == 2009 && _month == 1 && _day == 1))		// 2009.1.1 exception
		throw DateException();
	else if ((_month == 1 || _month == 3 || _month == 5 || _month == 7 ||\
				_month == 8 || _month == 10 || _month == 12) && (_day < 1 || _day > 31))
		throw DateException();
	else if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && \
				(_day < 1 || _day > 30))
		throw DateException();
	else if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
	{
		if (_month == 2 && (_day < 1 || _day > 29))
			throw DateException();
	}
	else if (_month == 2 && (_day < 1 || _day > 28))
		throw DateException();
}

void	BitcoinExchange::checkValue(std::string &value)
{
	int	sum_of_point = 0;

//	std::cout << "value: " << value << std::endl;		// delete
	if (value[0] == '-')						// NotPositiveException
		throw NotPositiveException();
	for (unsigned int i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
			sum_of_point++;
		if (!isdigit(value[i]) && value[i] != '.')
			throw ValueException();				//	ValueException
	}
	if (sum_of_point > 1)
		throw ValueException();
	double	dValue = std::strtod(value.c_str(), NULL);
	if (dValue > 1000)
		throw TooLargeException();
}

double	BitcoinExchange::findRate()
{
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		if (compareDate(it->first))
		{
			it--;
			return it->second;
		}
	}
	std::map<std::string, double>::iterator it = _data.end();
	it--;
	if (!compareDate(it->first))
		return it->second;
	return 0;
}

bool	BitcoinExchange::compareDate(const std::string& first)
{
	std::stringstream ss(first);
	std::string token;
	int year, month, day;

	std::getline(ss, token, '-');
	year = static_cast<int>(std::strtod(token.c_str(), NULL));

	std::getline(ss, token, '-');
	month = static_cast<int>(std::strtod(token.c_str(), NULL));

	std::getline(ss, token);
	day = static_cast<int>(std::strtod(token.c_str(), NULL));

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


void	BitcoinExchange::printResult(std::string& date, std::string& value, double& rate)
{
	double dvalue = std::strtod(value.c_str(), NULL);

	std::stringstream ss(date);
	std::string token;

	std::getline(ss, token, '-');
	std::cout << token << "-";

	std::getline(ss, token, '-');
	std::cout << token << "-";

	std::getline(ss, token, '-');
	std::cout << token ;//<< std::endl;

	std::cout << " => " << value << " = " << std::fixed << dvalue * rate << std::endl;
}

const char* BitcoinExchange::OpenFileException::what() const throw()
{
	return "Error: could not open file";
}

const char* BitcoinExchange::InputException::what() const throw()
{
	return "Error: bad input";
}

const char* BitcoinExchange::DelimException::what() const throw()
{
	return "Error: bad delimiter";
}

const char* BitcoinExchange::DateException::what() const throw()
{
	return "Error: bad date";
}

const char* BitcoinExchange::NotPositiveException::what() const throw()
{
	return "Error: not a positive number";
}

const char* BitcoinExchange::ValueException::what() const throw()
{
	return "Error: bad value";
}

const char* BitcoinExchange::TooLargeException::what() const throw()
{
	return "Error: too large a number";
}
