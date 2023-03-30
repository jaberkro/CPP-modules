#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter
{
	public:
		static void	convert(std::string input);

	private:
		static char		_cvalue;
		static int		_ivalue;
		static float	_fvalue;
		static double	_dvalue;

		static void	setFromChar(std::string input);
		static void	setFromInteger(std::string input);
		static void	setFromFloat(std::string input);
		static void	setFromDouble(std::string input);

		static char		getChar(void);
		static int		getInteger(void);
		static float	getFloat(void);
		static double	getDouble(void);

		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &src);
		~ScalarConverter();
};

#endif
