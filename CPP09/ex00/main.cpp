#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

std::string lowerYear(std::string date)
{
	date.at(5) = '1';
	date.at(6) = '2';
	date.at(8) = '3';
	date.at(9) = '1';
	if (date.at(3) > '0')
		date.at(3)--;
	else if (date.at(2) > '0')
	{
		date.at(2)--;
		date.at(3) = '9';
	}
	return (date);
}

std::string lowerMonth(std::string date)
{
	if ((date.at(5) > '0' && date.at(6) > '0') || (date.at(5) == '0' && date.at(6) > '1'))
		date.at(6)--;
	else
	{
		date.at(5)--;
		date.at(6) = '9';
	}
	if (date.at(5) == '0' && date.at(6) == '2')
	{
		date.at(8) = '2';
		if ((date.at(2) == '1' && date.at(3) == '2') || (date.at(2) == '1' && date.at(3) == '6') || \
			(date.at(2) == '2' && date.at(3) == '0'))
			date.at(9) = '9';
		else
			date.at(9) = '8';
	}
	else if ((date.at(5) == '0' && date.at(6) == '4') || (date.at(5) == '0' && date.at(6) == '6') || \
			(date.at(5) == '0' && date.at(6) == '9') || (date.at(5) == '1' && date.at(6) == '1'))
	{
		date.at(8) = '3';
		date.at(9) = '0';
	}
	else
	{
		date.at(8) = '3';
		date.at(9) = '1';
	}
	return (date);
}

std::string lowerDate(std::string date)
{
	if ((date.at(8) > '0' && date.at(9) > '0') || (date.at(8) == '0' && date.at(9) > '1'))
		date.at(9)--;
	else if (date.at(8) > '0')
	{
		date.at(8)--;
		date.at(9) = '9';
	}
	else if ((date.at(5) == '0' && date.at(6) > '1') || date.at(5) > '0')
		date = lowerMonth(date);
	else
		date = lowerYear(date);
	return (date);
}


float findValue(std::string line, BitcoinExchange &btc)
{
	float			value;
	std::string		date = line.substr(0, 10);

	while (!(date.at(2) == '0' && date.at(3) == '8'))
	{
		try
		{
			value = btc._map.at(date.substr(0, 10));
			return (value);
		}
		catch(const std::exception& e)
		{
			date = lowerDate(date);
		}
	}
	std::cout << "Error: bad input => [" << line.substr(0, 10) << std::endl;
	return (-1.0);
}

int	isFloat(std::string toCheck)
{
	size_t i = 0;
	size_t dotCount = 0;

	while (i < toCheck.size())
	{
		if (!isdigit(toCheck.at(i)) && toCheck.at(i) != '.')
			return (0);
		if (toCheck.at(i) == '.' && (i != 0 && i != toCheck.size() - 1))
			dotCount++;
		else if (toCheck.at(i) == '.')
			return (0);
		i++;
	}
	if (dotCount > 1 || (dotCount == 1 && (toCheck.size() < 3 || (toCheck.size() == 3 && toCheck.at(1) != '.'))))
		return (0);
	return (1);
}

int	isInt(std::string toCheck)
{
	size_t i = 0;

	while (i < toCheck.size())
	{
		if (!isdigit(toCheck.at(i)))
			return (0);
		i++;
	}
	return (1);
}

int	validValue(std::string value)
{
	double val;

	if (value.at(0) == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (0);
	}
	else if (isInt(value) || isFloat(value))
	{
		try
		{
			val = std::stod(value);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			return (0);
		}
		if (isInt(value) && val <= 0)
			std::cout << "Error: too small a number." << std::endl;
		else if (isInt(value) && val >= 1000)
			std::cout << "Error: too large a number." << std::endl;
		else if (isInt(value) || isFloat(value))
		{
			return (1);
		}
	}
	else
	{
		std::cout << "Error: not a float or integer => [" << value  << "]" << std::endl;
		return (0);
	}
	return (0);
}

int validDate(std::string date)
{
	int	year;
	int	month;
	int	day;

	if (!isdigit(date.at(0)) || !isdigit(date.at(1)) || !isdigit(date.at(2)) || !isdigit(date.at(3)) || \
		!isdigit(date.at(5)) || !isdigit(date.at(6)) || !isdigit(date.at(8)) || !isdigit(date.at(9)) || \
		date.at(4) != '-' || date.at(7) != '-' || date.length() != 10)
		return (0);
	try
	{
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 6));
		day = std::stoi(date.substr(8, 9));
	}
	catch(const std::exception& e)
	{
		return (0);
	}
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
		return (0);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (0);
	if (month == 2 && ((day > 29 && year % 4 == 0) || (day > 28 && year % 4 != 0)))
		return (0);
	return (1);
}

int	validLine(std::string line)
{
	if (line.find(" | ") == std::string::npos)
	{
		std::cout << "Error: bad input => [" << line << "]" << std::endl;
		return (0);
	}
	if (!validDate(line.substr(0, line.find(" | "))))
	{
		std::cout << "Error: bad input => [" << line.substr(0, line.find(" | ")) << "]" << std::endl;
		return (0);
	}
	if (!validValue(line.substr(line.find(" | ") + 3)))
	{
		return (0);
	}
	return (1);
}

void	processFile(std::ifstream &userFile)
{
	std::string		line;
	float			value;
	float			amount;
	BitcoinExchange	btc;

	std::getline(userFile, line);
	while (userFile)
	{
		std::getline(userFile, line);
		
		if (line == "")
			break;
		if (validLine(line))
		{
			try
			{
				amount = std::stof(line.substr(13));
			}
			catch(const std::exception& e)
			{
				std::cout << "Error: not a float or integer => [" << line.substr(3)  << "]" << std::endl; 
			}
			value = findValue(line, btc);
			if (value != -1.0)
				std::cout << line.substr(0, 10) << " => " << amount << " = " << value * amount << std::endl;
		}
	}
}

int main (int argc, char **argv)
{
	std::ifstream userFile;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	userFile.open(argv[1]);
	if (!userFile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	processFile(userFile);
	userFile.close();
	return 0;
}
