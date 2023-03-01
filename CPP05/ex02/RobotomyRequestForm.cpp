#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << "Default constructor called on RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	*this = src;
	std::cout << "Copy constructor called on RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	//copy variables
	std::cout << "Copy assignment operator called on RobotomyRequestForm" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called on RobotomyRequestForm" << std::endl;
}
