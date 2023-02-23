/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:01 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/23 16:52:12 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void	leak_checker(void)
{
	system("leaks abstract -q");
}

int	main(void)
{
	{
		// AAnimal	AAnimal; //uncommenting and compiling this should give an error
		Cat		cat;
		Dog		dog;

		// const AAnimal* AAnimalAAnimal = new AAnimal();
		// const AAnimal* AAnimalCat = new Cat();
		// const AAnimal* AAnimalDog = new Dog();

		const Cat* cat2 = new Cat();
		const Dog* dog2 = new Dog();

		std::cout << "\nDefault constructor used:\n";
		// std::cout << AAnimal.getType() << " says: ";
		// AAnimal.makeSound();
		std::cout << cat.getType() << " says: ";
		cat.makeSound();
		std::cout << dog.getType() << " says: ";
		dog.makeSound();

		std::cout << "\nCopy assignment operator used:\n";
		// std::cout << AAnimalAnimal->getType() << " says: ";
		// AAnimalAnimal->makeSound();
		// std::cout << AAnimalCat->getType() << " says: ";
		// AAnimalCat->makeSound();
		// std::cout << AAnimalDog->getType() << " says: ";
		// AAnimalDog->makeSound();
		std::cout << cat2->getType() << " says: ";
		cat2->makeSound();
		std::cout << dog2->getType() << " says: ";
		dog2->makeSound();

		std::cout << std::endl;
		// delete AAnimalAnimal;
		// delete AAnimalCat;
		// delete AAnimalDog;
		delete cat2;
		delete dog2;
		std::cout << std::endl;
		atexit(leak_checker);
	}
	return (0);
}
