#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();
	
	public:
		// isfunc()~

		static char		toChar(double _dValue);
		static int		toInt(double* _dValue);
		static float	toFloat(double _dValue);
		static double	toDouble(double _dValue);

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

//		static void		conversion(double _dValue);
		static void		convert(std::string& literal);

};

#endif
