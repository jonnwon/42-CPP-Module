#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter()
{
}


ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

char ScalarConverter::toChar(double _dValue)
{
	if (!isprint(_dValue) && _dValue >= std::numeric_limits<char>::min() \
			&& _dValue <= std::numeric_limits<char>::max())
		throw NondisplayableException();
	if (!isprint(_dValue))
		throw ImpossibleException();
	return static_cast<char>(_dValue);
}

int		ScalarConverter::toInt(double _dValue)
{
	if (_dValue != _dValue)
		throw ImpossibleException();
	else if (_dValue == std::numeric_limits<double>::infinity()\
			|| _dValue == -std::numeric_limits<double>::infinity())
		throw ImpossibleException();
	else if (_dValue < std::numeric_limits<int>::min()\
			|| _dValue > std::numeric_limits<int>::max())
		throw ImpossibleException();
	return static_cast<int>(_dValue);
}


float	ScalarConverter::toFloat(double _dValue)
{
	if (_dValue == std::numeric_limits<double>::infinity()\
		|| _dValue == -std::numeric_limits<double>::infinity())
		return static_cast<float>(_dValue);
	if (_dValue < -std::numeric_limits<float>::max()\
			|| _dValue > std::numeric_limits<float>::max())
		throw ImpossibleException();
	return static_cast<float>(_dValue);
}


double	ScalarConverter::toDouble(double _dValue)
{
	if (_dValue == std::numeric_limits<double>::infinity()\
		|| _dValue == -std::numeric_limits<double>::infinity())
		return static_cast<double>(_dValue);
	if (_dValue < -std::numeric_limits<double>::max()\
		|| _dValue > std::numeric_limits<double>::max())
		throw ImpossibleException();
	return static_cast<double>(_dValue);
}

const char* ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}

const char* ScalarConverter::NondisplayableException::what() const throw()
{
	return "Non displayable";
}

void	ScalarConverter::conversion(double _dValue)
{
	try
	{
		std::cout << "char: ";
		char res = ScalarConverter::toChar(_dValue);
		std::cout << "'" << res << "'" << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ScalarConverter::NondisplayableException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "int: " << ScalarConverter::toInt(_dValue) << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		std::cout << e.what() << std::endl;;
	}

	try
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << toFloat(_dValue) << "f" << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "double: " << std::fixed << std::setprecision(1) << toDouble(_dValue) << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
