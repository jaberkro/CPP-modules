#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		class	BadOriginalDatabaseException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	NoProvidedDatabaseException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	IncorrectUsageException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	BadEntryException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	BadDateException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	BadValueException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void	setOriginalDatabaseName(std::string originalDatabase);
		const	std::string & getOriginalDatabaseName(void);
		void	setProvidedDatabaseName(std::string ProvidedDatabase);
		const	std::string & getProvidedDatabaseName(void);

		void	initDatabase(void);
		void	processProvidedDatabase(void);

	private:
		std::string						_originalDatabaseName;
		std::string						_providedDatabaseName;
		std::string						_startDate;
		std::map<std::string, float>	_exchangeRateMap;

		std::ifstream	openDatabase(std::string databaseName);
		void			validateDate(std::string entry);
		void			validateValue(std::string entry);
		void			printEntryValue(std::string entry);
		float			findExchangeRate(std::string entry);
};

#endif
