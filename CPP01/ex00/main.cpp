/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:48 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 13:14:52 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    Zombie  jacob;
    Zombie  bella("Bella");
    Zombie  *edward = newZombie("Edward");

    randomChump("Carlisle");
    jacob.announce();
    bella.announce();
    edward->announce();
    delete (edward);
    return (0);
}
