/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:48 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/08/25 20:44:57 by jaberkro      ########   odam.nl         */
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

    randomChump("Vultury");
    jacob.announce();
    bella.announce();
    edward->announce();
    delete (edward);
    return (0);
}
