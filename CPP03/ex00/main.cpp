/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:31 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/23 10:43:35 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	{
		ClapTrap nameless;

		std::cout << std::endl;
		nameless.attack("Peter");
		nameless.takeDamage(1);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.beRepaired(3);
		nameless.takeDamage(3);
		nameless.takeDamage(40);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		ClapTrap harl("Harl");
		ClapTrap helga = harl;

		std::cout << std::endl;
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
		std::cout << std::endl;
	}
	return (0);
}
