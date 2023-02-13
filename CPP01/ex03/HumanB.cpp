/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:39:59 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 16:22:27 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    std::cout << "HumanB: Default constructor called on " << this->_name << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB: Destructor called on " << this->_name << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	std::cout << this->_name << " sets weapon";
	if (this->_weapon)
		std::cout << " from " << this->_weapon->getType();
	this->_weapon = &weapon;
	std::cout << " to " << this->_weapon->getType() << std::endl;
}

