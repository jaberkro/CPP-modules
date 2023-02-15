/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:01 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 20:53:52 by jaberkro      ########   odam.nl         */
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
	Cat minoes;
	Dog	bello;
	// const Animal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const Animal* i = new WrongCat();

	std::cout << minoes.getType() << " says: ";
	minoes.makeSound();

	std::cout << bello.getType() << " says: ";
	bello.makeSound();

	std::cout << i->getType() << " says: ";
	i->makeSound();
	std::cout << j->getType() << " says: ";
	j->makeSound();


	return (0);
}
