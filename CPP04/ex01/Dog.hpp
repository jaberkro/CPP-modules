/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:06 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/23 16:33:15 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		Dog& operator=(const Dog &src);
		~Dog();

	virtual void			makeSound(void) const;
	virtual std::string		getIdea(int index) const;
	virtual void			setIdea(std::string idea);
	virtual int				countIdeas(void) const;

	private:
		Brain*		_brain;
};

#endif
