/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:59 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 21:51:54 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _name("Anonymous"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called on ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parametric constructor called on ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called on ClapTrap" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy assignment operator called on ClapTrap" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called on ClapTrap" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of the game and can not attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has not enough energy points to attack ";
		std::cout << target << "!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of the game and can not take damage!" << std::endl;
		return ;
	}
	if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " lost all hit points and is out of the game!" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of the game and can not repair itself!" << std::endl;
		return ;
	}
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself with " << amount << " hit points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has not enough energy points to repair itself!" << std::endl;
	}
}
