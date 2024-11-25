#include "BitcoinExchange.hpp"

static std::string lowerYear(std::string date)
{
	date.at(5) = '1';
	date.at(6) = '2';
	date.at(8) = '3';
	date.at(9) = '1';
	if (date.at(3) > '0')
	{
		date.at(3)--;
	}
	else if (date.at(2) > '0')
	{
		date.at(2)--;
		date.at(3) = '9';
	}
	else if (date.at(1) > '0')
	{
		date.at(1)--;
		date.at(2) = '9';
		date.at(3) = '9';
	}
	else if (date.at(0) > '0')
	{
		date.at(0)--;
		date.at(1) = '9';
		date.at(2) = '9';
		date.at(3) = '9';
	}
	return (date);
}

static std::string lowerMonth(std::string date)
{
	if ((date.at(5) > '0' && date.at(6) > '0') || (date.at(5) == '0' && date.at(6) > '1'))
	{
		date.at(6)--;
	}
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
		{
			date.at(9) = '9';
		}
		else
		{
			date.at(9) = '8';
		}
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

static std::string lowerDay(std::string date)
{
	if ((date.at(8) > '0' && date.at(9) > '0') || (date.at(8) == '0' && date.at(9) > '1'))
	{
		date.at(9)--;
	}
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

float BitcoinExchange::findExchangeRate(std::string entry)
{
	float			exchangeRate;
	std::string		date = entry.substr(0, 10);

	while (!(date.at(0) == this->_startDate.at(0) && date.at(1) == this->_startDate.at(1) && \
		date.at(2) == this->_startDate.at(2) && date.at(3) == this->_startDate.at(3) && \
		date.at(5) == this->_startDate.at(5) && date.at(6) == this->_startDate.at(6) && \
		date.at(8) == this->_startDate.at(8) && date.at(9) == this->_startDate.at(9)))
	{
		try
		{
			exchangeRate = this->_exchangeRateMap.at(date.substr(0, 10));
			return (exchangeRate);
		}
		catch(const std::exception& e)
		{
			date = lowerDay(date);
		}
	}
	throw BitcoinExchange::BadDateException();
}

