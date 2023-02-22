/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:17 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 16:36:31 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal& operator=(const AAnimal &src);
		virtual ~AAnimal();

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;

	protected:
		std::string	_type;
};

#endif
