/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:06 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 16:39:35 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>

class Dog: public AAnimal
{
	public:
		Dog();
		Dog(const Dog &src);
		Dog& operator=(const Dog &src);
		~Dog();

	virtual void makeSound(void) const;

	protected:
		Brain*		_brain;
};

#endif
