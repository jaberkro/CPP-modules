/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:57:50 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 20:56:04 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <string>
# include "Animal.hpp"

class WrongCat: public Animal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat& operator=(const WrongCat &src);
		~WrongCat();

		virtual void makeSound(void) const;
};

#endif
