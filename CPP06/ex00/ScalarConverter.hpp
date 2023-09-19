#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		std::string _input;
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& rhs);
	
	public:
		ScalarConverter(std::string input);
		~ScalarConverter();

		char	toChar() const;
		int		toInt() const;
		float	toFloat() const;
		double	toDouble() const;

		class ImpossibleException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NondisplayableException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator <<(std::ostream& outputStream, const ScalarConverter& rhs);

#endif
