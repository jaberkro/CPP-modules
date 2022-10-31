/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:40:42 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/10/31 16:57:49 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <stdlib.h>
#include "PhoneBook.hpp"

int	ft_stoi(std::string input)
{
	if (input[1] == '\0')
	{
		return (int(input[0]) - 48);
	}
	return (0);
}

int	getNumberInput(void)
{
	int			input;
	std::string	input_text;

	while (42)
	{
		getline(std::cin, input_text);
		input = ft_stoi(input_text);
		if (input > 0 && input < 9)
			break;
		std::cout << input_text << ": Incorrect input: Should be a number between 1 and 8\n";
		std::cout << "Give index of the contact to display: (1-8)" << std::endl;
	}
	return (input);
}

int	main(void)
{
	PhoneBook	book;
	std::string	input;
	int			contactNum;

	contactNum = 0;
	std::cout << "\nFind your F•R•I•E•N•D•S over here:\n";
	std::cout << "Type ADD, SEARCH or EXIT to add a new contact, search for a contact or exit the program" << std::endl;
	getline(std::cin, input);
	while (42)
	{
		if (input.compare("EXIT") == 0 || std::cin.fail())
			break ;
		if (input.compare("ADD") == 0)
		{
			book.addContact(contactNum % 8);
			std::cout << "Added " << book.getContactName(contactNum % 8) << " to F•R•I•E•N•D•S" << std::endl;
			contactNum++;
		}
		else if (input.compare("SEARCH") == 0)
		{
			std::cout << "F•R•I•E•N•D•S:" << std::endl;
			book.displayContacts();
			std::cout << "Give index of the contact to display: (1-8)" << std::endl;
			book.displayContact(getNumberInput() - 1);
		}
		std::cout << "Type ADD, SEARCH or EXIT to add a new contact, search for a contact or exit the program" << std::endl;
		getline(std::cin, input);
		
	}
	std::cout << "See you next time! I'll be there for you <3\n" << std::endl;
	return (0);
}
