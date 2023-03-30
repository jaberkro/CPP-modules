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
	try
	{
		_cvalue = input.at(0);
		_ivalue = static_cast<int>(_cvalue);
		_fvalue = static_cast<float>(_cvalue);
		_dvalue = static_cast<double>(_cvalue);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ScalarConverter::setFromInteger(std::string input)
{
	try
	{
		_ivalue = static_cast<int>(stoi(input));
		if (_ivalue >= 40 && _ivalue < 127)
			_cvalue = static_cast<char>(_ivalue);
		else
			_cvalue = -1;
		_fvalue = static_cast<float>(_ivalue);
		_dvalue = static_cast<double>(_ivalue);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ScalarConverter::setFromFloat(std::string input)
{
	try
	{
		_fvalue = stof(input);
		if (_fvalue >= 40.0 && _fvalue < 127.0)
			_cvalue = static_cast<char>(_fvalue);
		else
			_cvalue = -1;
		if (input == "-inff" || input == "+inff")
			_ivalue = std::numeric_limits<int>::infinity();
		else
			_ivalue = static_cast<int>(_fvalue);
		_dvalue = static_cast<double>(_fvalue);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ScalarConverter::setFromDouble(std::string input)
{
	try
	{
		_dvalue = stod(input);
		if (_dvalue >= 40.0 && _dvalue < 127.0)
			_cvalue = static_cast<char>(_dvalue);
		else
			_cvalue = -1;
		if (input == "-inf" || input == "+inf")
			_ivalue = std::numeric_limits<int>::infinity();
		else
			_ivalue = static_cast<int>(_dvalue);
		_fvalue = static_cast<float>(_dvalue);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
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
	if (c == 0)
		std::cout << "Non displayable" << std::endl;
	else if (c == -1)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

static void	printInteger(int i)
{
	std::cout << "int: " << i << std::endl;
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

void	ScalarConverter::convert(std::string input)
{
	if (input.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return ;
	}

	if (isalpha(input.at(0)) && input.size() == 1)
		setFromChar(input);
	else if ((input.back() == 'f' && input.size() > 1 && isdigit(input.at(input.size() - 2))) || \
		input == "-inff" || input == "+inff" || input == "nanf")
		setFromFloat(input);
	else if ((input.find('.', 1) >= 0 && input.find('.', 1) < input.size()) || \
		input == "-inf" || input == "+inf" || input == "nan")
		setFromDouble(input);
	else if (isdigit(input.at(0)) || ((input.at(0) == '+' || input.at(0) == '-') && input.at(1) && isdigit(input.at(1))))
		setFromInteger(input);
	else
	{
		std::cout << "Error: invalid input" << std::endl;
		return ;
	}

	printChar(getChar());
	printInteger(getInteger());
	printFloat(getFloat());
	printDouble(getDouble());
}

//not working yet: int 0, int inff int nan etc
