/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 16:14:20 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 17:13:02 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		std::string getType(void);
		void setType(std::string type);

	private:
		std::string _type;
};

#endif
