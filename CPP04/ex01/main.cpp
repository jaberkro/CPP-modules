/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:01 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 16:33:38 by jaberkro      ########   odam.nl         */
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
	{
		Animal	animal;
		Cat		cat;
		Dog		dog;

		const Animal* animalAnimal = new Animal();
		const Animal* animalCat = new Cat();
		const Animal* animalDog = new Dog();

		WrongAnimal	wrongAnimal;
		WrongCat	wrongCat;

		const WrongAnimal* wrongAnimalWrongAnimal = new WrongAnimal();
		const WrongAnimal* wrongAnimalWrongCat = new WrongCat();

		std::cout << "\nDefault constructor used:\n";
		std::cout << animal.getType() << " says: ";
		animal.makeSound();
		std::cout << cat.getType() << " says: ";
		cat.makeSound();
		std::cout << dog.getType() << " says: ";
		dog.makeSound();

		std::cout << "\nCopy assignment operator used:\n";
		std::cout << animalAnimal->getType() << " says: ";
		animalAnimal->makeSound();
		std::cout << animalCat->getType() << " says: ";
		animalCat->makeSound();
		std::cout << animalDog->getType() << " says: ";
		animalDog->makeSound();

		std::cout << "\nDefault constructor used:\n";
		std::cout << wrongAnimal.getType() << " says: ";
		wrongAnimal.makeSound();
		std::cout << wrongCat.getType() << " says: ";
		wrongCat.makeSound();

		std::cout << "\nCopy assignment operator used:\n";
		std::cout << wrongAnimalWrongAnimal->getType() << " says: ";
		wrongAnimalWrongAnimal->makeSound();
		std::cout << wrongAnimalWrongCat->getType() << " says: ";
		wrongAnimalWrongCat->makeSound();

		std::cout << std::endl;
		delete animalAnimal;
		delete animalCat;
		delete animalDog;
		delete wrongAnimalWrongAnimal;
		delete wrongAnimalWrongCat;
		std::cout << std::endl;
	}
	std::cout << "\n------------------------------------------------------------------" << std::endl;
	{
		int	size = 50;
		const Animal *animals[50];

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
	}
	// system("leaks polymorphism");
	return (0);
}
