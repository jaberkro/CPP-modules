/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 12:52:41 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/18 12:13:22 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;

}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*pmf)(void) = NULL;

	if (level.compare("DEBUG") == 0 || level.compare("INFO") == 0 || \
		level.compare("WARNING") == 0 || level.compare("ERROR") == 0)
	{
		switch(level.at(0))
		{
			case 'D':
				pmf = &Harl::debug;
				break ;
			case 'I':
				pmf = &Harl::info;
				break ;
			case 'W':
				pmf = &Harl::warning;
				break ;
			case 'E':
				pmf = &Harl::error;
				break ;
		}
		(this->*pmf)();
		return ;
	}
	std::cout << "Error: wrong complain level inserted" << std::endl;
}
