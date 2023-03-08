#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "Nobody";
	std::cout << "Default constructor called on PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	std::cout << "Parametric constructor called on PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
	*this = src;
	std::cout << "Copy constructor called on PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->_target = src._target;
	std::cout << "Copy assignment operator called on PresidentialPardonForm" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor called on PresidentialPardonForm" << std::endl;
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " had been pardoned by Zaphod Beeblebrox." << std::endl;
}
