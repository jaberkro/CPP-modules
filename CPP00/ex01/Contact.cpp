/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:05:03 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/11/02 12:50:28 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact: Default constructor called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact: Default destructor called" << std::endl;
}

static std::string	getInput(void)
{
	std::string	input;

	while (42)
	{
		getline(std::cin, input);
		if (input != "")
			break ;
		std::cout << "Invalid input. Please try again" << std::endl;
	}
	return (input);
}

void	Contact::setName(void)
{
	std::string input;

	input = getInput();
	this->_name = input;
}

void	Contact::setSurname(void)
{
	std::string input;

	input = getInput();
	this->_surname = input;
}

void	Contact::setNickname(void)
{
	std::string input;

	input = getInput();
	this->_nickname = input;
}

void	Contact::setNumber(void)
{
	std::string input;

	input = getInput();
	this->_number = input;
}

void	Contact::setSecret(void)
{
	std::string input;

	input = getInput();
	this->_secret = input;
}

std::string	Contact::getName(void) const
{
	return (this->_name);
}

std::string	Contact::getSurname(void) const
{
	return (this->_surname);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getNumber(void) const
{
	return (this->_number);
}

std::string	Contact::getSecret(void) const
{
	return (this->_secret);
}
