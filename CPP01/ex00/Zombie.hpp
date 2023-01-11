/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:58 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 13:14:57 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        
        void announce( void );

    private:
        std::string  _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
