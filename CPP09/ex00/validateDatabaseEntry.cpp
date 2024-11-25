#include "BitcoinExchange.hpp"

static int	isFloat(std::string toCheck)
{
	size_t i = 0;
	size_t dotCount = 0;

	while (i < toCheck.size())
	{
		if (!isdigit(toCheck.at(i)) && toCheck.at(i) != '.')
		{
			return (0);
		}
		if (toCheck.at(i) == '.' && (i != 0 && i != toCheck.size() - 1))
		{
			dotCount++;
		}	
		else if (toCheck.at(i) == '.')
		{
			return (0);
		}	
		i++;
	}
	if (dotCount > 1 || (dotCount == 1 && (toCheck.size() < 3 || (toCheck.size() == 3 && toCheck.at(1) != '.'))))
	{	
		return (0);
	}
	return (1);
}

static int	isInt(std::string toCheck)
{
	size_t i = 0;

	while (i < toCheck.size())
	{
		if (!isdigit(toCheck.at(i)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	BitcoinExchange::validateValue(std::string valueString)
{
	float value;

	if (valueString.at(0) == '-')
	{
		throw BitcoinExchange::BadValueException();
	}
	else if (isInt(valueString) || isFloat(valueString))
	{
		try
		{
			value = std::stof(valueString);
		}
		catch(const std::exception& e)
		{
			throw BitcoinExchange::BadValueException();
		}
		if (value < 0.0 || value >= 1000.0)
		{
			throw BitcoinExchange::BadValueException();
		}
	}
	else
	{
		throw BitcoinExchange::BadValueException();
	}
}

void BitcoinExchange::validateDate(std::string date)
{
	int	year;
	int	month;
	int	day;

	if (!isdigit(date.at(0)) || !isdigit(date.at(1)) || !isdigit(date.at(2)) || !isdigit(date.at(3)) || \
		!isdigit(date.at(5)) || !isdigit(date.at(6)) || !isdigit(date.at(8)) || !isdigit(date.at(9)) || \
		date.at(4) != '-' || date.at(7) != '-' || date.length() != 10)
	{
		throw BitcoinExchange::BadDateException();
	}
	try
	{
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 6));
		day = std::stoi(date.substr(8, 9));
	}
	catch(const std::exception& e)
	{
		throw BitcoinExchange::BadDateException();
	}
	if (year < 1900 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31 || \
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || \
		(month == 2 && ((day > 29 && year % 4 == 0) || (day > 28 && year % 4 != 0))))
	{
		throw BitcoinExchange::BadDateException();
	}	
}
