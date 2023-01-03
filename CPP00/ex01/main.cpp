/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:40:42 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/03 15:48:15 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	getNumberInput(void)
{
	int			input;
	std::string	input_text;

	while (42)
	{
		getline(std::cin, input_text);
		if (input_text.size() == 1 && isdigit(input_text.at(0)))
		{
			input = stoi(input_text);
			if (input > 0 && input < 9)
				break;
		}
		std::cout << input_text << ": Incorrect input: Should be a number between 1 and 8\n";
		std::cout << "Give index of the contact to display: (1-8)" << std::endl;
	}
	return (input);
}

int	main(void)
{
	PhoneBook	book;
	std::string	input;
	int			contactNum = 0;

	std::cout << "\nFind your F•R•I•E•N•D•S over here:\n";
	while (42)
	{
		std::cout << "Type ADD, SEARCH or EXIT to add a new contact, search for a contact or exit the program" << std::endl;
		getline(std::cin, input);
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
	}
	std::cout << "\nSee you next time! I'll be there for you <3\n" << std::endl;
	return (0);
}
