/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:09 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/27 13:52:39 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Default constructor called on Dog" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Copy constructor called on Dog" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "Copy assignment operator called on Dog" << std::endl;
	this->_type = src._type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Destructor called on Dog" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woofff" << std::endl;
}
