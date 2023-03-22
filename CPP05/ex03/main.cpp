#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	testLeaks(void)
{
	system("leaks intern -q");
}

int	main(void)
{
	Intern		luke;
	Bureaucrat	ben("Ben", 2);

	std::srand(std::time(nullptr));
	
	std::cout << std::endl;
	AForm* bender = luke.makeForm("robotomy request", "Bender");
		

	ben.signForm(*bender);
	ben.executeForm(*bender);

	std::cout << std::endl;
	delete bender;
	std::cout << std::endl;
	atexit(testLeaks);
	return (0);	
}
