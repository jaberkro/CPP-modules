/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:46 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 17:46:01 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frog("Frog");

	frog.attack("Chicken");
	frog.beRepaired(100);
	frog.takeDamage(1000);
	frog.takeDamage(10);
	frog.highFivesGuys();
	return (0);
}
