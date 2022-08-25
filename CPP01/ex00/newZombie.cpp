/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/08/25 20:41:45 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie  *newZombie = new Zombie(name);
    
    return (newZombie);
}
