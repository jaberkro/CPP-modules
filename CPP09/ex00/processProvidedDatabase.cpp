#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

void BitcoinExchange::printEntryValue(std::string entry)
{
	float	exchangeRate;
	float	value;

	try
	{
		value = std::stof(entry.substr(13));
	}
	catch(const std::exception& e)
	{
		throw BitcoinExchange::BadValueException();
	}
	exchangeRate = findExchangeRate(entry);
	std::cout << entry.substr(0, 10) << " => " << value << " = " << exchangeRate * value << std::endl;
}

void BitcoinExchange::processProvidedDatabase(void)
{
	std::ifstream	providedDatabase;
	std::string		entry;

	providedDatabase.open(this->_providedDatabaseName);
	if (!providedDatabase.is_open())
	{
		throw BitcoinExchange::NoProvidedDatabaseException();
	}
	std::getline(providedDatabase, entry);
	while (std::getline(providedDatabase, entry))
	{
		try
		{
			if (entry.find(" | ") != 10)
			{
				throw BitcoinExchange::BadEntryException();
			}
			validateDate(entry.substr(0, 10));
			validateValue(entry.substr(13));
			printEntryValue(entry);
		}
		catch(const BitcoinExchange::BadEntryException& e)
        {
            std::cout << "Error: bad input => " << entry << ": "<< e.what() << std::endl;
        }        
        catch(const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
	}
	providedDatabase.close();
}
