/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 19:05:38 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 16:52:14 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ScavTrap sally("Sally");
	
	sally.guardGate();
	sally.attack("Henry");
	sally.beRepaired(10);
	sally.takeDamage(110);
	sally.beRepaired(10);
	sally.guardGate();
	sally.attack("Henry");
	return (0);
}
