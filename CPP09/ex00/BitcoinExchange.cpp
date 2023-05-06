#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	dataFile;
	std::string		line;

	dataFile.open("data.csv");
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		try
		{
			if (line.size() > 11)
				this->_map[line.substr(0, 10)] = std::stof(line.substr(11));
		}
		catch(const std::exception& e)
		{
			std::cout << "exception: " << e.what() << std::endl;
			dataFile.close();
			return ;
		}
	}
	dataFile.close();
	std::cout << "Default constructor called on BitcoinExchange" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	std::cout << "Copy constructor called on BitcoinExchange" << std::endl;
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	std::cout << "Copy assignment operator called on BitcoinExchange" << std::endl;
	this->_map = src._map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "Destructor called on BitcoinExchange" << std::endl;
}
