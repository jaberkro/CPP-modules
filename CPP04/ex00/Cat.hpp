/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:12 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 20:55:28 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &src);
		Cat& operator=(const Cat &src);
		~Cat();

		virtual void makeSound(void) const;
};

#endif
