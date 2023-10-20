#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_data;
		int								_year;
		int								_month;
		int								_day;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void	readDatabase(std::string& database);
		void	printData();
		void	readInputFile(std::string &inputFile);
		void	checkDate(std::string &date);
		void	checkValue(std::string &value);
		double	findRate();
		bool	compareDate(const std::string& first);
		void	printResult(std::string& date, std::string& value, double& rate);

		

	
	class OpenFileException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class InputException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class DelimException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class DateException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class NotPositiveException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class ValueException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class TooLargeException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};


#endif
