/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:56:19 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 18:50:38 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "Default constructor called on ScavTrap" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "Parametric constructor called on ScavTrap" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "Copy constructor called on ScavTrap" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "Assignment operator called on ScavTrap" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called on ScavTrap" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of the game and can not attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " has not enough energy points to attack ";
		std::cout << target << "!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of the game and can not go into guard keeper mode!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode." << std::endl;
}
