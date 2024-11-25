#include "BitcoinExchange.hpp"
#include <fstream>
# include <iostream>

std::ifstream BitcoinExchange::openDatabase(std::string databaseName)
{
	std::ifstream	database;
	std::string		startDateEntry;

	database.open(databaseName);
	if (!database.is_open())
	{
		throw BitcoinExchange::BadOriginalDatabaseException();
	}
	std::getline(database, startDateEntry);
	return (database);
}

void BitcoinExchange::initDatabase(void)
{
	std::ifstream	database;
	std::string		entry;
	
	database = openDatabase(this->_originalDatabaseName);
	while (std::getline(database, entry))
	{
		try
		{
			validateDate(entry.substr(0, 10));
			this->_exchangeRateMap[entry.substr(0, 10)] = std::stof(entry.substr(11));
			if (this->_startDate == "0000-01-01")
			{
				this->_startDate = entry.substr(0, 10);
			}			
		}
		catch(const std::exception& e)
		{
			database.close();
			throw BitcoinExchange::BadOriginalDatabaseException();
		}
	}
	database.close();
}
