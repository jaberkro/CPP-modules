/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:40:03 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 17:55:26 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        
		void	attack(void);

    private:
        std::string	_name;
		Weapon		&_weapon;
};


#endif
