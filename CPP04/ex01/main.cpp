/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:01 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 16:25:50 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	int	size = 50;
	Animal *animals[50];

	std::cout << std::endl;
	for (int i = 0; i < size / 2; i ++)
	{
		animals[i] = new Cat();
	}

	std::cout << std::endl;
	for (int i = size / 2; i < size; i++)
	{
		animals[i] = new Dog();
	}
	
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		delete animals[i];
	}
	
	std::cout << std::endl;
	// system("leaks polymorphism");
	return (0);
}
