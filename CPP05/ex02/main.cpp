#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	PresidentialPardonForm	obama("Obama");
	ShrubberyCreationForm	bush("Bush");
	RobotomyRequestForm		pinochio("Pinochio");
	Bureaucrat				ben("Ben", 2);
	Bureaucrat				janitor("Janitor", 120);

	//make random really random
	std::srand(std::time(nullptr));

	//obama gets executed by ben
	std::cout << std::endl;
	std::cout << obama << std::endl;
	try
	{
		obama.execute(ben);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//obama gets signed by ben
	std::cout << obama << std::endl;
	try
	{
		obama.beSigned(ben);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//obama gets executed by ben
	std::cout << obama << std::endl;
	try
	{
		obama.execute(ben);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	//ben signs bush
	std::cout << std::endl;
	std::cout << bush << std::endl;
	try
	{
		ben.signForm(bush);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//ben executes bush
	std::cout << bush << std::endl;
	try
	{
		ben.executeForm(bush);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//robotomy gets signed by ben
	std::cout << std::endl;
	std::cout << pinochio << std::endl;
	try
	{
		pinochio.beSigned(ben);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//robotomy gets executed by ben
	std::cout << pinochio << std::endl;
	try
	{
		std::cout << std::endl;
		pinochio.execute(ben);
		pinochio.execute(ben);
		pinochio.execute(ben);
		pinochio.execute(ben);
		pinochio.execute(ben);
		pinochio.execute(ben);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//ben executes pinochio, after that the janitor tries to execute pinochio
	std::cout << std::endl;
	std::cout << pinochio << std::endl;
	try
	{
		std::cout << std::endl;
		ben.executeForm(pinochio);
		ben.executeForm(pinochio);
		ben.executeForm(pinochio);
		ben.executeForm(pinochio);
		ben.executeForm(pinochio);
		ben.executeForm(pinochio);
		janitor.executeForm(pinochio);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return (0);	
}
