#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>

// data.csv ������ map �� ���� ����
// 

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void	readDatabase(std::string &database);
		void	printData();
		void	readInputfile(std::string &inputfile);

	
	class OpenFileExecption : std::exception
	{
		virtual const char* what() const throw();
	};


};

#endif
