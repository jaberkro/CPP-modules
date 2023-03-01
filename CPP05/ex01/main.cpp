#include "Form.hpp"
#include <iostream>

int	main(void)
{
	Form a("A", 50, 100);
	Form b("B", 21, 120);
	Form c("C", 2, 150);
	Form d("D", 20, 150);

	Bureaucrat harl("Harl", 20);

	std::cout << std::endl;
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

	std::cout << std::endl;
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

	std::cout << std::endl;
	std::cout << c << std::endl;
	harl.signForm(c);
	std::cout << c << std::endl;

	std::cout << std::endl;
	std::cout << d << std::endl;
	harl.signForm(d);
	std::cout << d << std::endl;
	std::cout << std::endl;

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

	return (0);
}
