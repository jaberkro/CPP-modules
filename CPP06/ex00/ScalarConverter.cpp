#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called on ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	std::cout << "Copy constructor called on ScalarConverter" << std::endl;
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "Copy assignment operator called on ScalarConverter" << std::endl;
	_cvalue = src._cvalue;
	_ivalue = src._ivalue;
	_fvalue = src._fvalue;
	_dvalue = src._dvalue;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called on ScalarConverter" << std::endl;
}

void	ScalarConverter::setFromChar(std::string input)
{
	_cvalue = input.at(0);
	_ivalue = static_cast<int>(_cvalue);
	_fvalue = static_cast<float>(_cvalue);
	_dvalue = static_cast<double>(_cvalue);
}

void	ScalarConverter::setFromInteger(std::string input)
{
	_ivalue = static_cast<int>(stoi(input));
	if (_ivalue >= 0 && _ivalue < 127)
		_cvalue = static_cast<char>(_ivalue);
	else
		_cvalue = -1;
	_fvalue = static_cast<float>(_ivalue);
	_dvalue = static_cast<double>(_ivalue);
}

void	ScalarConverter::setFromFloat(std::string input)
{
		_fvalue = stof(input);
		if (_fvalue >= 0.0 && _fvalue < 127.0)
			_cvalue = static_cast<char>(_fvalue);
		else
			_cvalue = -1;
		if (input == "-inff" || input == "+inff")
			_ivalue = -2147483648;
		else
			_ivalue = static_cast<int>(_fvalue);
		_dvalue = static_cast<double>(_fvalue);
}

void	ScalarConverter::setFromDouble(std::string input)
{
	_dvalue = stod(input);
	if (_dvalue >= 0.0 && _dvalue < 127.0)
		_cvalue = static_cast<char>(_dvalue);
	else
		_cvalue = -1;
	if (input == "-inf" || input == "+inf")
		_ivalue = -2147483648;
	else
		_ivalue = static_cast<int>(_dvalue);
	_fvalue = static_cast<float>(_dvalue);
}

char	ScalarConverter::getChar(void)
{
	return(_cvalue);
}

int		ScalarConverter::getInteger(void)
{
	return(_ivalue);
}

float	ScalarConverter::getFloat(void)
{
	return(_fvalue);
}

double	ScalarConverter::getDouble(void)
{
	return(_dvalue);
}

static void	printChar(char c)
{
	std::cout  << "char: ";
	if (c >= 0 && c <= 39)
		std::cout << "Non displayable" << std::endl;
	else if (c == -1)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

static void	printInteger(int i)
{
	std::cout << "int: ";
	if (i == -2147483648)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

static void	printFloat(float f)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
}

static void	printDouble(double d)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
}

static void printValues(char c, int i, float f, double d)
{
	if ((i < -1000000 || i > 1000000) && i != -2147483648)
	{
		std::cerr << "Error: input out of range [-1000000, 1000000]" << std::endl;
		return ;
	}
	printChar(c);
	printInteger(i);
	printFloat(f);
	printDouble(d);
}

static int isChar(std::string input)
{
	if ((input.at(0) >= 40 && input.at(0) < 127 && input.size() == 1) && (input.at(0) < 48 || input.at(0) > 57))
		return (1);
	return (0);
}

static int isInteger(std::string input)
{
	if ((isdigit(input.at(0)) || ((input.at(0) == '+' || input.at(0) == '-') && input.at(1) && isdigit(input.at(1)))) && input.find('.', 1) < 0)
		return (1);
	return (0);
}

static int isFloat(std::string input)
{
	if ((input.back() == 'f' && input.size() > 1 && isdigit(input.at(input.size() - 2))) || \
			input == "-inff" || input == "+inff" || input == "nanf")
		return (1);
	return (0);
}

static int isDouble(std::string input)
{
	if ((input.find('.', 1) >= 0 && input.back() != '.') || \
			input == "-inf" || input == "+inf" || input == "nan")
		return (1);
	return (0);	
}

static int error_found(std::string input)
{
	if (input.empty())
	{
		std::cerr << "Error: empty string" << std::endl;
		return (1);
	}
	else if (input.size() > 10)
	{
		std::cerr << "Error: string too long: max 10 characters in range [-1000000, 1000000]" << std::endl;
		return (1);
	}
	else if (input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff" || input == "nan" || input == "nanf")
		;
	else if ((!isdigit(input.at(0)) && input.at(0) != '+' && input.at(0) != '-') && input.size() > 1)
	{
		std::cerr << "Error: invalid input: " << input << ": multiple chars" << std::endl;
		return (1);
	}
	else if (input.size() > 1 && (input.find('-', 1) != std::string::npos || input.find('+', 1) != std::string::npos || \
		((input.at(0) == '+' || input.at(0) == '-') && !isdigit(input.at(1)))))
	{
		std::cerr << "Error: invalid input: " << input << ": wrong usage of signs" << std::endl;
		return (1);
	}
	else if (isdigit(input.at(0)) || ((input.at(0) == '+' || input.at(0) == '-') && input.size() > 1 && isdigit(input.at(1))))
	{
		for (size_t i = 1; i < input.size(); i++)
		{
			if (!isdigit(input.at(i)) && input.at(i) != '.' && input.at(i) != 'f')
			{
				std::cerr << "Error: invalid input: " << input << ": wrong usage of chars" << std::endl;
				return (1);
			}
			else if (input.at(i) == '.' && (i == input.size() - 1 || !isdigit(input.at(i + 1))))
			{
				std::cerr << "Error: invalid input: " << input << ": wrong usage of '.'" << std::endl;
				return (1);
			}
			else if (input.at(i) == 'f' && (i != input.size() - 1 || !isdigit(input.at(i - 1))))
			{
				std::cerr << "Error: invalid input: " << input << ": wrong usage of f" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

void	ScalarConverter::convert(std::string input)
{
	if (error_found(input))
		return ;
	try
	{
		if (isChar(input))
			setFromChar(input);
		else if (isFloat(input))
			setFromFloat(input);
		else if (isDouble(input))
			setFromDouble(input);
		else if (isInteger(input))
			setFromInteger(input);
		else
		{
			std::cerr << "Error: invalid input: " << input << ": not a char, integer, float or double" << std::endl;
			return ;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: ";
		std::cerr << e.what() << '\n';
		return ;
	}
	printValues(getChar(), getInteger(), getFloat(), getDouble());
}
