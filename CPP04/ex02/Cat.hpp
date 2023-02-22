/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:12 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 16:39:43 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>

class Cat: public AAnimal
{
	public:
		Cat();
		Cat(const Cat &src);
		Cat& operator=(const Cat &src);
		~Cat();

		virtual void makeSound(void) const;

	protected:
		Brain*		_brain;
};

#endif
