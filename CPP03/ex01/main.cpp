/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:38 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 17:32:26 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ScavTrap nameless;
	ScavTrap sally("Sally");
	ScavTrap copyCat = nameless;

	nameless.guardGate();
	sally.guardGate();
	copyCat.guardGate();

	sally.attack("copyCat");
	copyCat.takeDamage(200);
	sally.beRepaired(10);
	copyCat.beRepaired(10);
	nameless.attack("Sally");
	sally.takeDamage(110);
	sally.beRepaired(10);
	sally.guardGate();
	sally.attack("Henry");
	return (0);
}
