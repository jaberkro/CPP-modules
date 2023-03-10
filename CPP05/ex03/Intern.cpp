#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Default constructor called on Intern" << std::endl;
}

Intern::Intern(const Intern &src)
{
	*this = src;
	std::cout << "Copy constructor called on Intern" << std::endl;
}

Intern& Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << "Copy assignment operator called on Intern" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Destructor called on Intern" << std::endl;
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	AForm*	form;
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	int i = 0;
	while (i < 3)
	{
		if (formName == forms[i])
			break ;
		i++;
	}
	switch(i)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break ;
		case 1:
			form = new PresidentialPardonForm(target);
			break ;
		case 2:
			form = new ShrubberyCreationForm(target);
			break ;
		default:
			std::cout << "Error: form to be created by intern does not exist" << std::endl;
			return (NULL);
	}
	std::cout << "Intern creates " << formName << std::endl;
	return (form);
}
