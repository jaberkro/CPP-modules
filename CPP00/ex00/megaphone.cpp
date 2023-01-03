/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 14:42:47 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/03 14:46:31 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	str_toupper(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		std::cout << str_toupper(argv[i]);
	}
	std::cout << std::endl;
	return 0;
}
