/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:46 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/23 10:59:53 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap frog("Frog");

	std::cout << std::endl;
	frog.highFivesGuys();
	frog.attack("Chicken");
	frog.beRepaired(100);
	frog.takeDamage(1000);
	frog.takeDamage(10);
	frog.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
