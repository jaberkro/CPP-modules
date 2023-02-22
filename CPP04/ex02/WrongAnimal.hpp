/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:57:47 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/17 16:36:52 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal& operator=(const WrongAnimal &src);
		~WrongAnimal();

		std::string getType(void) const;
		void makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
