#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &src);
		~ScalarConverter();

		void	convert(std::string input);

	private:
		char	_cvalue;
		int		_ivalue;
		float	_fvalue;
		double	_dvalue;

		void	setFromChar(std::string input);
		void	setFromInteger(std::string input);
		void	setFromFloat(std::string input);
		void	setFromDouble(std::string input);

		char	getChar(void);
		int		getInteger(void);
		float	getFloat(void);
		double	getDouble(void);
};

#endif
