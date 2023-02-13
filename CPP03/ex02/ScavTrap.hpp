/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:56:21 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 17:01:39 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap &scavtrap);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif
