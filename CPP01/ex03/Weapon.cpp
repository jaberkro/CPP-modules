/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:39:19 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 16:22:39 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void) : _type("bare hands")
{
	std::cout << "Weapon: Default constructor called\n";
}

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon: Copy constructor called\n";
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon: Destructor called\n";
}

std::string	Weapon::getType(void)
{
	std::string &typeReference = this->_type;

	return (typeReference);
}

void	Weapon::setType(std::string newType)
{
	std::cout << "Weapon changed from " << this->_type;
	this->_type = newType;
	std::cout << " to " << this->_type << std::endl;
}
