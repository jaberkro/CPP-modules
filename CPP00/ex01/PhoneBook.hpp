/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:04:53 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/10/13 16:52:58 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <cctype>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		// contacts[3].initContact;
		
		void addContact(int contactNum);

		void	initPhoneBook(void);
		std::string getContactName(int i) const;
		std::string getContactSurname(int i) const;
		std::string getContactNickname(int i) const;
		std::string getContactNumber(int i) const;
		std::string getContactSecret(int i) const;
		void	displayContacts();
		void	displayContact(int index);

	private:
		Contact _contacts[8];
};

#endif
