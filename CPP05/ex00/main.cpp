#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat ben("Ben", 20);
	Bureaucrat elly("Elly", 220);
	Bureaucrat frank("Frank", -20);

	std::cout << std::endl;
	std::cout << ben << std::endl;
	std::cout << elly << std::endl;
	std::cout << frank << std::endl;
	std::cout << std::endl;

	std::cout << ben << std::endl;
	ben.incrementGrade();
	std::cout << ben << std::endl;
	ben.decrementGrade();
	std::cout << ben << std::endl;
	std::cout << std::endl;

	return (0);
}
