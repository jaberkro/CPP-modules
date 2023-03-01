#include "PresidentialCreationForm.hpp"
#include <iostream>

PresidentialCreationForm::PresidentialCreationForm(void)
{
	std::cout << "Default constructor called on PresidentialCreationForm" << std::endl;
}

PresidentialCreationForm::PresidentialCreationForm(const PresidentialCreationForm &src)
{
	*this = src;
	std::cout << "Copy constructor called on PresidentialCreationForm" << std::endl;
}

PresidentialCreationForm& PresidentialCreationForm::operator=(const PresidentialCreationForm &src)
{
	//copy variables
	std::cout << "Copy assignment operator called on PresidentialCreationForm" << std::endl;
	return (*this);
}

PresidentialCreationForm::~PresidentialCreationForm(void)
{
	std::cout << "Destructor called on PresidentialCreationForm" << std::endl;
}

virtual void	execute(Bureaucrat const& executor) const
{
	std::cout << 
}
