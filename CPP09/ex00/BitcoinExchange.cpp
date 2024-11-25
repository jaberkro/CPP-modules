#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange(void): _startDate("0000-01-01")
{
	// std::cout << "Default constructor called on BitcoinExchange" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	// std::cout << "Copy constructor called on BitcoinExchange" << std::endl;
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	// std::cout << "Copy assignment operator called on BitcoinExchange" << std::endl;
	this->_originalDatabaseName = src._originalDatabaseName;
	this->_providedDatabaseName = src._providedDatabaseName;
	this->_startDate = src._startDate;
	this->_exchangeRateMap = src._exchangeRateMap;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "Destructor called on BitcoinExchange" << std::endl;
}

const char* BitcoinExchange::BadOriginalDatabaseException::what() const throw()
{
	return ("Error: could not open or parse original database file");
}

const char* BitcoinExchange::NoProvidedDatabaseException::what() const throw()
{
	return ("Error: could not open provided database file");
}

const char* BitcoinExchange::IncorrectUsageException::what() const throw()
{
	return ("Usage: ./btc <yourDatabaseName>");
}

const char* BitcoinExchange::BadEntryException::what() const throw() 
{
;
	return ("entry should be in the format '<date> | <value>'. Example: '2009-12-23 | 1.2'");
}

const char* BitcoinExchange::BadDateException::what() const throw()
{
	return ("date should be between 1900 and 2025");
}

const char* BitcoinExchange::BadValueException::what() const throw()
{
	return ("value should be a positive number between 0 and 1000");
}

const std::string & BitcoinExchange::getProvidedDatabaseName(void)
{
	return (this->_providedDatabaseName);
}

void BitcoinExchange::setProvidedDatabaseName(std::string providedDatabaseName)
{
	this->_providedDatabaseName = providedDatabaseName;
}

const std::string & BitcoinExchange::getOriginalDatabaseName(void)
{
	return (this->_originalDatabaseName);
}

void BitcoinExchange::setOriginalDatabaseName(std::string originalDatabase)
{
	this->_originalDatabaseName = originalDatabase;
}
