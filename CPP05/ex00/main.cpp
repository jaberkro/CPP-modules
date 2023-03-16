#include "Bureaucrat.hpp"
#include <iostream>

void	testLeaks(void)
{
	system("leaks bureaucrat -q");
}

int	main(void)
{

	std::cout << "\n-----------------------------WORKS-----------------------------" << std::endl;
	try
	{
		Bureaucrat ben("Ben", 20);
		Bureaucrat copy = ben;
		Bureaucrat *ptr = new Bureaucrat();

		std::cout << std::endl;
		std::cout << ben << std::endl;
		ben.incrementGrade();
		std::cout << ben << std::endl;
		ben.decrementGrade();
		std::cout << ben << std::endl;
		std::cout << std::endl;

		std::cout << copy << std::endl;
		std::cout << *ptr << std::endl;
		std::cout << std::endl;
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------------------TOO LOW-----------------------------" << std::endl;
	try
	{
		Bureaucrat elly("Elly", 220);
		std::cout << elly << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------------------TOO HIGH----------------------------" << std::endl;
	try
	{
		Bureaucrat frank("Frank", -20);
		std::cout << frank << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "\n-----------------------------INCREMENT FAILS----------------------------" << std::endl;
	try
	{
		Bureaucrat harl("Harl", 2);
		std::cout << harl << std::endl;
		harl.incrementGrade();
		std::cout << harl << std::endl;
		harl.incrementGrade();
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------------------DECREMENT FAILS----------------------------" << std::endl;
	try
	{
		Bureaucrat karl("Karl", 149);
		std::cout << karl << std::endl;
		karl.decrementGrade();
		std::cout << karl << std::endl;
		karl.decrementGrade();
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	atexit(testLeaks);
	return (0);
}
