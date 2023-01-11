/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:37:57 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 18:08:11 by jaberkro      ########   odam.nl         */
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
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
	return 0;
}
// {
// 	Weapon club;
// 	Weapon spike("superspike");
// 	HumanA bob("Bob", club);
	
// 	std::cout << club.Weapon::getType() << std::endl;
// 	club.Weapon::setType("wooden club");
// 	std::cout << club.Weapon::getType() << std::endl;

// 	std::cout << spike.Weapon::getType() << std::endl;

// }
// {