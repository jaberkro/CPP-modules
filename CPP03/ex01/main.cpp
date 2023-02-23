/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:38 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/23 10:53:36 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap nameless;
	ScavTrap sally("Sally");
	ScavTrap copyCat = nameless;
	ScavTrap *newScav = new ScavTrap(sally);
	
	std::cout << std::endl;
	nameless.guardGate();
	sally.guardGate();
	copyCat.guardGate();
	newScav->guardGate();
	
	std::cout << std::endl;
	sally.attack("copyCat");
	copyCat.takeDamage(200);
	sally.beRepaired(10);
	copyCat.beRepaired(10);
	nameless.attack("Sally");
	sally.takeDamage(110);
	sally.beRepaired(10);
	sally.guardGate();
	sally.attack("Henry");
	
	std::cout << std::endl;
	delete newScav;
	std::cout << std::endl;
	return (0);
}
