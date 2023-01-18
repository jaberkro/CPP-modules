/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:37:57 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/18 12:16:15 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	std::cout << std::endl;
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	std::cout << std::endl;
	}
	{
	Weapon club = Weapon("crude spiked club");
	Weapon sword = Weapon("excalibur");
	HumanB jim("Jim");
	std::cout << std::endl;
	jim.attack();
	jim.setWeapon(sword);
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	std::cout << std::endl;
	}
	return 0;
}
