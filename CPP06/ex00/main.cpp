#include "ScalarConverter.hpp"
#include <iostream>

char	ScalarConverter::_cvalue = 0;
int		ScalarConverter::_ivalue = 0;
float	ScalarConverter::_fvalue = 0.0f;
double	ScalarConverter::_dvalue = 0.0;

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <input>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	return (0);
}
