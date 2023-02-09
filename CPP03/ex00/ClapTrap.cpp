/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:59 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/09 19:45:19 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _name("anonymous")
{
	std::cout << "Default constructor called on ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Copy constructor called on ClapTrap" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "Copy assignment operator called on ClapTrap" << std::endl;
	this->_name = claptrap._name;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called on ClapTrap" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of the game and can not attack anymore!" << std::endl;
		return ;
	}
	if (this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has not enough energy points to attack ";
		std::cout << target << "!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hit_points -= amount;
	}
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " lost all hit points and is out of the game!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of the game and can not repair itself!" << std::endl;
		return ;
	}
	if (this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself with " << amount << " hit points!" << std::endl;
		this->_hit_points += amount;
		this->_energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has not enough energy points to repair itself!" << std::endl;
	}
}
