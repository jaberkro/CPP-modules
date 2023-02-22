/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 18:38:30 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 21:00:53 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain &src);
		Brain& operator=(const Brain &src);
		~Brain();

		std::string	getIdea(int index) const;
		void		setIdea(std::string idea);
		int			getIndex(void) const;
		void		setIndex(int const index);

	private:
		std::string _ideas[100];
		int			_index;
};

#endif
