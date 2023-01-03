/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:04:53 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/03 15:46:03 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		void		initPhoneBook(void);
		void 		addContact(int contactNum);

		std::string getContactName(int i) const;
		std::string getContactSurname(int i) const;
		std::string getContactNickname(int i) const;
		std::string getContactNumber(int i) const;
		std::string getContactSecret(int i) const;

		void		displayContacts();
		void		displayContact(int index);

	private:
		Contact _contacts[8];
};

#endif
