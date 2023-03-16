#include "Form.hpp"
#include <iostream>

void	testLeaks(void)
{
	system("leaks form -q");
}

int	main(void)
{

	std::cout << "\n-----------------------------CONSTRUCTION FAILS-----------------------------" << std::endl;
	try
	{
		Form fail("Fail", 250, 100);
		std::cout << fail << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Form a("A", 50, 100);
	Form b("B", 21, 120);
	Form c("C", 2, 150);
	Form d("D", 20, 150);

	Bureaucrat harl("Harl", 20);

	std::cout << "\n-----------------------------WORKS-----------------------------" << std::endl;
	try
	{
		std::cout << a << std::endl;
		a.beSigned(harl);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------------------WORKS-----------------------------" << std::endl;
	try
	{
		std::cout << b << std::endl;
		b.beSigned(harl);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------------------GRADE TOO LOW-----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << c << std::endl;
	harl.signForm(c);
	std::cout << c << std::endl;

	std::cout << "\n-----------------------------WORKS-----------------------------" << std::endl;
	std::cout << d << std::endl;
	harl.signForm(d);
	std::cout << d << std::endl;
	std::cout << std::endl;
	
	std::cout << "\n-----------------------------WORKS (WITH NEW)-----------------------------" << std::endl;
	Form *f = NULL;

	try
	{
		f = new Form("lol", 100, 100);
		std::cout << *f << std::endl;
		delete f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	atexit(testLeaks);
	return (0);
}
