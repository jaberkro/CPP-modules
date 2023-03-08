#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "Nobody";
	std::cout << "Default constructor called on RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "Parametric constructor called on RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	*this = src;
	std::cout << "Copy constructor called on RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->_target = src._target;
	std::cout << "Copy assignment operator called on RobotomyRequestForm" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called on RobotomyRequestForm" << std::endl;
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "Brrrrrrrt!" << std::endl;
	std::cout << "Brrrt!" << std::endl;
	std::cout << "Brrrrrrrrrrrrt!" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl; 
}
