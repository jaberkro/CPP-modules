/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:59:58 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/08/25 20:28:12 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CPP
# define ZOMBIE_CPP
# include <iostream>
# include <cctype>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        
        void announce(void);

    private:
        std::string  _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
