/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:48 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/10/31 17:09:01 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie  jacob;
    Zombie  bella("Bella");
    Zombie  *edward = newZombie("Edward");
    Zombie  *groupies;
    int     horde_size = 5;

    randomChump("Carlisle");
    jacob.announce();
    bella.announce();
    edward->announce();
    groupies = zombieHorde(horde_size, "Vultury");
    for (int i = 0; i < horde_size; i++)
        groupies[i].announce();
    delete[] (groupies);
    delete (edward);
    return (0);
}
