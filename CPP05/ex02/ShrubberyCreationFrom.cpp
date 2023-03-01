#include "ShrubberyCreationFrom.hpp"
#include <iostream>

ShrubberyCreationFrom::ShrubberyCreationFrom(void)
{
	std::cout << "Default constructor called on ShrubberyCreationFrom" << std::endl;
}

ShrubberyCreationFrom::ShrubberyCreationFrom(const ShrubberyCreationFrom &src)
{
	*this = src;
	std::cout << "Copy constructor called on ShrubberyCreationFrom" << std::endl;
}

ShrubberyCreationFrom& ShrubberyCreationFrom::operator=(const ShrubberyCreationFrom &src)
{
	//copy variables
	std::cout << "Copy assignment operator called on ShrubberyCreationFrom" << std::endl;
	return (*this);
}

ShrubberyCreationFrom::~ShrubberyCreationFrom(void)
{
	std::cout << "Destructor called on ShrubberyCreationFrom" << std::endl;
}
