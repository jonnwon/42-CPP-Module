#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>
// data.csv 내용을 map 을 통해 저장
// 

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_data;
		double							_year;		// in inputfile
		double							_month;
		double							_day;


	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void	readDatabase(std::string& database);
		void	printData();
		void	readInputfile(std::string& inputfile);
		void	check_date(std::string& date);
		void	check_value(std::string& value);
		double	findRate();
		bool	compDate(const std::string& first);

		void	printData2(std::string& date, std::string& value, double& rate)
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

		void	printValue(std::string& value)
		{
			std::stringstream ss(value);
			std::string token;

			std::cout << " => " << token; // << std::endl;
		}


	
	class OpenFileException : public std::exception
	{
		virtual const char * what() const throw();
	};

	class BadInputException : public std::exception
	{
		virtual const char * what() const throw();
	};

	class TooLargeException : public std::exception
	{
		virtual const char * what() const throw();
	};

	class NotPositiveException : public std::exception
	{
		virtual const char * what() const throw();
	};

//	class InvalidInputException : public std::exception
//	{
//		virtual const char * what() const throw();
//	};
};

#endif
