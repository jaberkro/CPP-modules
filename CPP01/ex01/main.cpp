/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:48 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/08/26 15:40:33 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "Zombie.hpp"

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
    // system("leaks zombie");
    return (0);
}
