/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:06 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 20:55:43 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		Dog& operator=(const Dog &src);
		~Dog();

	virtual void makeSound(void) const;
};

#endif
