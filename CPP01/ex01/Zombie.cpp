/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:55 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/10/31 17:18:00 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : _name("Jacob")
{
    std::cout << "Zombie: Default constructor called\n";
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie: Default constructor called\n";
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie: Default destructor called on " << this->_name << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}
