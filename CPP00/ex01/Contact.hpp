/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:05:00 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/10/31 16:51:16 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	public:
		Contact();
		~Contact();
		
		void initContact(void);
		
		void	setName(void);
		void	setSurname(void);
		void	setNickname(void);
		void	setNumber(void);
		void	setSecret(void);
		
		std::string	getName(void) const;
		std::string	getSurname(void) const;
		std::string	getNickname(void) const;
		std::string	getNumber(void) const;
		std::string	getSecret(void) const;

	private:
		std::string _name;
		std::string _surname;
		std::string _nickname;
		std::string _number;
		std::string _secret;
};

#endif
