#include "ScalarConverter.hpp"

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

bool		ScalarConverter::isCharLiteral(std::string& str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool		ScalarConverter::isIntLiteral(std::string& str)
{
	bool	sign	= false;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return false;
		if (str[i] == '+' || str[i] == '-')
		{
			if (sign)
				return false;
			sign = true;
		}
	}
	return true;
}

bool		ScalarConverter::isFloatLiteral(std::string& str)
{
	size_t	len				= str.length();
	bool	decimalPoint	= false;
	bool	sign			= false;

	if (len < 4 || (str[len - 1] != 'f' && str[len - 1] != 'F'))
		return false;
	for (size_t i = 0; i < len - 1; i++)
	{
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '.')
			return false;
		else if (str[i] == '.')
		{
			if (decimalPoint)
				return false;
			decimalPoint = true;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (sign)
				return false;
			sign = true;
		}
	}
	return true;
}

bool		ScalarConverter::isDoubleLiteral(std::string& str)
{
	size_t	len				= str.length();
	bool	decimalPoint	= false;
	bool	sign			= false;

	if (len < 3 || str[len -1] == '.')
		return false;
	for (size_t i = 0; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '.')
			return false;
		else if (str[i] == '.')
		{
			if (decimalPoint)
				return false;
			decimalPoint = true;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (sign)
				return false;
			sign = true;
		}
	}
	return true;
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
	if (_dValue != _dValue)		// check nan
		throw ImpossibleException();
	if (_dValue == std::numeric_limits<double>::infinity()\
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

void	ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
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

void		ScalarConverter::convert(std::string& literal)
{
	double _dValue;
	int idx = -1;

	bool (*p[4])(std::string& str) = {&isCharLiteral, &isIntLiteral, &isFloatLiteral, &isDoubleLiteral};

	for (int i = 0; i < 4; i++)
	{
		if (p[i](literal) == true)
		{
			idx = i;
			break ;
		}
	}

	switch (idx)
	{
		case -1:
			if (literal == "+inf" || literal == "+inff" || \
				literal == "-inf" || literal == "-inff" || \
				literal == "nan" || literal == "nanf")
			{
				_dValue = static_cast<double>(stod(literal));
				ScalarConverter::conversion(_dValue);
				break;
			}
			std::cout << "Error: Invalid argument" << std::endl;
			break;
		case 0:
			_dValue = static_cast<double>(literal[1]);
			ScalarConverter::conversion(_dValue);
			break;
		case 1:
			_dValue = static_cast<double>(stod(literal));

			if (_dValue < std::numeric_limits<int>::min() || _dValue > std::numeric_limits<int>::max())
			{
				printImpossible();
				return ;
			}
			ScalarConverter::conversion(_dValue);
			break;
		case 2:
			_dValue = static_cast<double>(stod(literal));
			if (_dValue < -std::numeric_limits<float>::max() || _dValue > std::numeric_limits<float>::max())
			{
				printImpossible();
				return ;
			}
			ScalarConverter::conversion(_dValue);
			break;
		case 3:
			_dValue = static_cast<double>(stod(literal));
			ScalarConverter::conversion(_dValue);
			break;
	}
}
