/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 15:01:54 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name)
{
    Zombie  *newZombie = new Zombie(name);
    
    return (newZombie);
}
