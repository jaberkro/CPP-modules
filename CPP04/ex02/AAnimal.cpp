/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:20 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/17 19:09:01 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void): _type("AAnimal")
{
	std::cout << "Default constructor called on AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Copy constructor called on AAnimal" << std::endl;
	*this = src;
}

AAnimal& AAnimal::operator=(const AAnimal &src)
{
	std::cout << "Copy assignment operator called on AAnimal" << std::endl;
	this->_type = src._type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor called on AAnimal" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
