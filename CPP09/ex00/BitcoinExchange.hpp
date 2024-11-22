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

		class	NoDatabaseException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	IncorrectUsageException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void setOriginalDatabase(std::string originalDatabase);
		const std::string & getOriginalDatabase(void);
		void initDatabase(void);
		void openFile(std::string userDataba);

		std::map<std::string, float>	_map;
		std::ifstream					_userDatabase;

	private:
		std::string						_originalDatabase;
};

#endif
