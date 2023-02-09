/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:31 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/09 19:46:00 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap harl("Harl");
	ClapTrap helga("Helga");
	
	harl.attack("Helga");
	harl.attack("Helga");
	harl.attack("Helga");
	harl.attack("Helga");
	harl.attack("Helga");
	harl.attack("Helga");
	harl.attack("Helga");
	harl.attack("Helga");
	harl.attack("Helga");
	harl.attack("Helga");
	
	harl.attack("Helga");
	harl.takeDamage(12);
	harl.beRepaired(3);
	helga.attack("Harl");
	helga.beRepaired(10);
	helga.takeDamage(10);
	helga.takeDamage(10);
	helga.beRepaired(10);
	return (0);
}
