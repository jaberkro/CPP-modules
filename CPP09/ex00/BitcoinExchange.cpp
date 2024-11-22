#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange(void)
{
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
	this->_originalDatabase = src._originalDatabase;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "Destructor called on BitcoinExchange" << std::endl;
}

const char* BitcoinExchange::NoOriginalDatabaseException::what() const throw()
{
	return ("Error: could not open original database file");
}

const char* BitcoinExchange::NoUserDatabaseException::what() const throw()
{
	return ("Error: could not open provided database file" + name);
}

const char* BitcoinExchange::IncorrectUsageException::what() const throw()
{

	return ("Usage: ./btc <yourDatabaseName");
}

void BitcoinExchange::initDatabase(void){
	std::ifstream	dataFile;
	std::string		line;

	dataFile.open(this->_originalDatabase);
	if (!dataFile.is_open())
	{
		throw BitcoinExchange::NoDatabaseException();
	}
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
			dataFile.close();
			throw e;
		}
	}
	dataFile.close();
}

const std::string & BitcoinExchange::getOriginalDatabase(void)
{
	return (this->_originalDatabase);
}

void BitcoinExchange::setOriginalDatabase(std::string originalDatabase)
{
	this->_originalDatabase = originalDatabase;
}
