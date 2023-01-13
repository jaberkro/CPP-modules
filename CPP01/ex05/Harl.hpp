/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 12:52:49 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/13 16:12:41 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
	
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};
