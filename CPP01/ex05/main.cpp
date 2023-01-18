/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 12:52:31 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/18 12:12:45 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl H;
	std::string level = "DEBUG";

	std::cout << "\nHERE WILL BE THE 4 DIFFERENT COMPLAIN LEVELS:" << std::endl;
	H.complain(level);
	level = "INFO";
	H.complain(level);
	level = "WARNING";
	H.complain(level);
	level = "ERROR";
	H.complain(level);

	std::cout << "\nHERE WILL BE SOME ERRORS:" << std::endl;
	level = "WRONG";
	H.complain(level);
	level = "Debug";
	H.complain(level);
	level = "debug";
	H.complain(level);
	level = "";
	H.complain(level);
	std::cout << std::endl;
}
