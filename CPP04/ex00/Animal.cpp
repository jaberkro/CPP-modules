/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:20 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/17 17:30:38 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void): _type("Animal")
{
	std::cout << "Default constructor called on Animal" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Copy constructor called on Animal" << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal &src)
{
	std::cout << "Copy assignment operator called on Animal" << std::endl;
	this->_type = src._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Destructor called on Animal" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << "*silence*" << std::endl;
}
