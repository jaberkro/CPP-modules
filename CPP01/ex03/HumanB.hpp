/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:39:54 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 18:08:55 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
        
		void	attack(void);
		void	setWeapon(Weapon &weapon);

    private:
        std::string	_name;
		Weapon		*_weapon;

		HumanB();
};

#endif
