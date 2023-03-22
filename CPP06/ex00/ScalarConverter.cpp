#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

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
	this->_cvalue = src._cvalue;
	this->_ivalue = src._ivalue;
	this->_fvalue = src._fvalue;
	this->_dvalue = src._dvalue;
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
		this->_cvalue = input.at(0);
		this->_ivalue = static_cast<int>(this->_cvalue);
		this->_fvalue = static_cast<float>(this->_cvalue);
		this->_dvalue = static_cast<double>(this->_cvalue);
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
		this->_ivalue = static_cast<int>(stoi(input));
		if (this->_ivalue >= 0 && this->_ivalue < 127)
			this->_cvalue = static_cast<char>(this->_ivalue);
		else
			this->_cvalue = -1;
		this->_fvalue = static_cast<float>(this->_ivalue);
		this->_dvalue = static_cast<double>(this->_ivalue);
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
		this->_fvalue = stof(input);
		if (this->_fvalue >= 0.0 && this->_fvalue < 127.0)
			this->_cvalue = static_cast<char>(this->_fvalue);
		else
			this->_cvalue = -1;
		if (input == "-inff")
			this->_ivalue = std::numeric_limits<int>::min();
		else if (input == "+inff")
			this->_ivalue = std::numeric_limits<int>::max();
		else
			this->_ivalue = static_cast<int>(this->_fvalue);
		this->_dvalue = static_cast<double>(this->_fvalue);
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
		this->_dvalue = stod(input);
		if (this->_dvalue >= 0.0 && this->_dvalue < 127.0)
			this->_cvalue = static_cast<char>(this->_dvalue);
		else
			this->_cvalue = -1;
		if (input == "-inf")
			this->_ivalue = std::numeric_limits<int>::min();
		else if (input == "+inf")
			this->_ivalue = std::numeric_limits<int>::max();
		else
			this->_ivalue = static_cast<int>(this->_dvalue);
		this->_fvalue = static_cast<float>(this->_dvalue);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

char	ScalarConverter::getChar(void)
{
	return(this->_cvalue);
}

int		ScalarConverter::getInteger(void)
{
	return(this->_ivalue);
}

float	ScalarConverter::getFloat(void)
{
	return(this->_fvalue);
}

double	ScalarConverter::getDouble(void)
{
	return(this->_dvalue);
}

static void	printChar(char c)
{
	std::cout << "char: ";
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
	std::cout << "float: " << f;
	if (static_cast<int>(f) == f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void	printDouble(double d)
{
	std::cout << "double: " << d;
	if (static_cast<int>(d) == d)
		std::cout << ".0";
	std::cout << std::endl;
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
		input == "-inff" || input == "+inff")
		setFromFloat(input);
	else if ((input.find('.', 1) >= 0 && input.find('.', 1) < input.size()) || \
		input == "-inf" || input == "+inf")
		setFromDouble(input);
	else if (isdigit(input.at(0)) || ((input.at(0) == '+' || input.at(0) == '-') && input.at(1) && isdigit(input.at(1))))
		setFromInteger(input);
	else if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else
	{
		std::cout << "Error: invalid input" << std::endl;
		return ;
	}

	printChar(this->getChar());
	printInteger(this->getInteger());
	printFloat(this->getFloat());
	printDouble(this->getDouble());
}
