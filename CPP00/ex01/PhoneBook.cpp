/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:04:56 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/03 15:46:05 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook: Default constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook: Default destructor called" << std::endl;
}

void PhoneBook::addContact(int contactNum)
{
	std::cout << "Contact name: ";
	this->_contacts[contactNum].setName();
	std::cout << "Contact surname: ";
	this->_contacts[contactNum].setSurname();
	std::cout << "Contact nickname: ";
	this->_contacts[contactNum].setNickname();
	std::cout << "Contact number: ";
	this->_contacts[contactNum].setNumber();
	std::cout << "Contact darkest secret: ";
	this->_contacts[contactNum].setSecret();
	std::cout <<std::endl;
}

std::string PhoneBook::getContactName(int i) const
{
	return (_contacts[i].getName());
}

std::string PhoneBook::getContactSurname(int i) const
{
	return (_contacts[i].getSurname());
}

std::string PhoneBook::getContactNickname(int i) const
{
	return (_contacts[i].getNickname());
}

std::string PhoneBook::getContactNumber(int i) const
{
	return (_contacts[i].getNumber());
}

std::string PhoneBook::getContactSecret(int i) const
{
	return (_contacts[i].getSecret());
}

static void	truncateInput(std::string to_print)
{
	unsigned long	len;

	len = to_print.size();
	while (len < 10)
	{
		std::cout << " ";
		len++;
	}
	for (int i = 0; i < 9; i++)
	{
		std::cout << to_print[i];
	}
	if (len == 10)
		std::cout << to_print[9];
	else
		std::cout << ".";
	std::cout << "|";
}

static void	printAllInfo(std::string name, std::string surname, std::string nickname, int index)
{
	std::cout << "|         " << index + 1 << "|";
	truncateInput(name);
	truncateInput(surname);
	truncateInput(nickname);
	std::cout << std::endl;
}

void PhoneBook::displayContacts(void)
{
	std::cout << ".___________________________________________." << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|     INDEX|      NAME|   SURNAME|  NICKNAME|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		printAllInfo(getContactName(i), getContactSurname(i), getContactNickname(i), i);
	}
	std::cout << "|__________|__________|__________|__________|\n" << std::endl;
}

void PhoneBook::displayContact(int index)
{
	std::cout << ".__________." << std::endl;
	std::cout << "|          |" << std::endl;
	std::cout << "|      NAME| " << getContactName(index) << std::endl;
	std::cout << "|   SURNAME| " << getContactSurname(index)<< std::endl;
	std::cout << "|  NICKNAME| " << getContactNickname(index)<< std::endl;
	std::cout << "|    NUMBER| " << getContactNumber(index)<< std::endl;
	std::cout << "|    SECRET| " << getContactSecret(index)<< std::endl;
	std::cout << "|__________|\n" << std::endl;
}
