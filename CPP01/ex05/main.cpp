/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 12:52:31 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/13 16:24:57 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl H;
	std::string level = "debug";

	std::cout << "\nHERE WILL BE THE 4 DIFFERENT COMPLAIN LEVELS:" << std::endl;
	H.complain(level);
	level = "info";
	H.complain(level);
	level = "warning";
	H.complain(level);
	level = "error";
	H.complain(level);

	std::cout << "\nHERE WILL BE SOME ERRORS:" << std::endl;
	level = "wrong";
	H.complain(level);
	level = "Debug";
	H.complain(level);
	level = "DEBUG";
	H.complain(level);
	level = "";
	H.complain(level);
	std::cout << std::endl;
}
