#include "Form.hpp"
#include <iostream>

int	main(void)
{
	Form a("A", 50, 100);
	Form b("B", 10, 120);
	Form c("C", 2, 150);

	Bureaucrat harl("Harl", 20);

	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;

	a.beSigned(harl);
	std::cout << a << std::endl;

	Form *k = NULL;

	try
	{
		k = new Form("lol", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *k << std::endl;

	return (0);
}
