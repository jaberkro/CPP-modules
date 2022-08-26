/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:55 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/08/26 12:21:05 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "Zombie.hpp"

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
