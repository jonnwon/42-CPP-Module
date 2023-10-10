#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();
	
	public:
		static bool		isCharLiteral(std::string& str);
		static bool		isIntLiteral(std::string& str);
		static bool		isFloatLiteral(std::string& str);
		static bool		isDoubleLiteral(std::string& str);

		static char		toChar(double _dValue);
		static int		toInt(double _dValue);
		static float	toFloat(double _dValue);
		static double	toDouble(double _dValue);

		static void		printImpossible();

		static void		printResult(double _dValue);
		static void		convert(std::string& literal);

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

#endif
