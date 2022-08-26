/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 15:44:56 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/08/26 16:08:29 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(void)
{
	std::string	theString = "HI THIS IS BRAIN";
	std::string	*stringPTR = &theString;
	std::string &stringREF = theString;

	std::cout << &theString << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	
	std::cout << theString << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return (0);
}
