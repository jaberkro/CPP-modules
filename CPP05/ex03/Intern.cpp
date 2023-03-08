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

// Intern::Intern(const Intern &src)
// {
// 	*this = src;
// 	std::cout << "Copy constructor called on Intern" << std::endl;
// }

// Intern& Intern::operator=(const Intern &src)
// {
// 	//something with src
// 	std::cout << "Copy assignment operator called on Intern" << std::endl;
// 	return (*this);
// }

Intern::~Intern(void)
{
	std::cout << "Destructor called on Intern" << std::endl;
}

AForm::AForm *	Intern::makeForm(std::string formName, std::string target)
{
	void	(Intern::*pmf)() = NULL;
	AForm::AForm	form;

	if (formName.compare("robotomy request") == 0 || formName.compare("presidential pardon") == 0 || \
		formName.compare("shrubbery creation") == 0)
	{
		switch(formName.at(0))
		{
			case 'r':
				pmf = &RobotomyRequestForm::RobotomyRequestForm;
				break ;
			case 'p':
				pmf = &PresidentialPardonForm::PresidentialPardonForm;
				break ;
			case 's':
				pmf = &ShrubberyCreationForm::ShrubberyCreationForm;
				break ;
		}
		std::cout << "Intern creates " << formName << std::endl;
		form = (this->*pmf)();
		return (&form);
	}
	std::cout << "Error: form to be created does not exist" << std::endl;
}
