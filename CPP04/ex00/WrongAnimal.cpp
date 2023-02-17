/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:57:56 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/17 16:51:42 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "Default constructor called on WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "Copy constructor called on WrongAnimal" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Copy assignment operator called on WrongAnimal" << std::endl;
	this->_type = src._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor called on WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Hakihakihaki" << std::endl;
}
