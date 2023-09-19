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
	if (this != &rhs)
	{
		_input = rhs._input;
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(std::string input)
:_input(input)
{
}

char ScalarConverter::toChar() const
{
	double _fValue;

	_fValue = std::atof(_input.c_str());
	if (!isprint(_fValue) && _fValue >= std::numeric_limits<char>::min() \
			&& _fValue <= std::numeric_limits<char>::max())
		throw NondisplayableException();
	if (!isprint(_fValue))
		throw ImpossibleException();
	return static_cast<char>(_fValue);
}

int		ScalarConverter::toInt() const
{
	double _dValue;

	_dValue = std::atof(_input.c_str());
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


float	ScalarConverter::toFloat() const
{
	double _dValue;

	_dValue = std::atof(_input.c_str());

	if (_dValue == std::numeric_limits<double>::infinity()\
		|| _dValue == -std::numeric_limits<double>::infinity())
		return static_cast<float>(_dValue);
	if (_dValue < -std::numeric_limits<float>::max()\
			|| _dValue > std::numeric_limits<float>::max())
		throw ImpossibleException();
	return static_cast<float>(_dValue);
}


double	ScalarConverter::toDouble() const
{
	double _dValue;

	_dValue = std::atof(_input.c_str());

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


std::ostream& operator <<(std::ostream& outputStream, const ScalarConverter& rhs)
{
	try
	{
		outputStream << "char: ";
		char res = rhs.toChar();
		outputStream << "'" << res << "'" << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		outputStream << e.what() << std::endl;
	}
	catch (ScalarConverter::NondisplayableException &e)
	{
		outputStream << e.what() << std::endl;
	}
	
	try
	{
		outputStream << "int: " << rhs.toInt() << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		outputStream << e.what() << std::endl;;
	}

	try
	{
		outputStream << "float: " << std::fixed << std::setprecision(1) << rhs.toFloat() << "f" << std::endl;

//		outputStream << "float: " << rhs.toFloat() << "f" << std::endl;

	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		outputStream << e.what() << std::endl;
	}

	try
	{
		outputStream << "double: " << std::fixed << std::setprecision(1) << rhs.toDouble() << std::endl;
//		outputStream << "double: " << rhs.toDouble() << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		outputStream << e.what() << std::endl;
	}
	
	return outputStream;
}

