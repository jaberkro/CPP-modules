#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main (int argc, char **argv)
{
	BitcoinExchange	btc;

	try {
		if (argc != 2)
		{
			throw BitcoinExchange::IncorrectUsageException();
		}
		btc.setOriginalDatabaseName("data.csv");
		btc.initDatabase();
		btc.setProvidedDatabaseName(argv[1]);
		btc.processProvidedDatabase();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
