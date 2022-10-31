/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 15:44:56 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/10/31 17:15:25 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	theString = "HI THIS IS BRAIN";
	std::string	*stringPTR = &theString;
	std::string &stringREF = theString;

	std::cout << "Address of the string variable:   " << &theString << std::endl;
	std::cout << "Memory address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << "\n" << std::endl;
	
	std::cout << "The value of the string variable:  " << theString << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
