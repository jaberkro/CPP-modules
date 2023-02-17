/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:17 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/17 19:07:05 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal &src);
		Animal& operator=(const Animal &src);
		virtual ~Animal();

		std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
