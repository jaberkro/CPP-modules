/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 14:05:31 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 15:03:24 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return (horde);
}
