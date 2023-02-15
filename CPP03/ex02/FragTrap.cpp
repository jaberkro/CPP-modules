/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 16:53:38 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 18:36:19 by jaberkro      ########   odam.nl         */
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
	std::cout << "Parametric constructor called on FragTrap" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "Copy constructor called on FragTrap" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Assignment operator called on FragTrap" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
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
