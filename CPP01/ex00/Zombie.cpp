/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:55 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 16:21:55 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void): _name("Jacob")
{
    std::cout << "Zombie: Default constructor called on " << this->_name << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
    std::cout << "Zombie: Copy constructor called on " << this->_name << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie: Destructor called on " << this->_name << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
