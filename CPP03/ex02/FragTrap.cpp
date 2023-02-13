/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 16:53:38 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 17:00:43 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "Default constructor called on FragTrap" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "Copy constructor called on FragTrap" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap &Fragtrap)
{
	std::cout << "Copy assignment operator called on FragTrap" << std::endl;
	this->_name = Fragtrap._name;
	this->_hitPoints = Fragtrap._hitPoints;
	this->_energyPoints = Fragtrap._energyPoints;
	this->_attackDamage = Fragtrap._attackDamage;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called on FragTrap" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is out of the game and can not ask for high fives!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " asks for high fives! :)" << std::endl;
}
