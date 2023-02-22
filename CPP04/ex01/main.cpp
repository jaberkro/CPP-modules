/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:01 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 20:57:36 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	{
		Cat		cat;
		Dog		dog;

		cat.setIdea("Sleep");
		cat.setIdea("Catch fly");
		std::cout << "\ncats' ideas:" << cat.countIdeas() << std::endl;
		for (int i = 0; i < cat.countIdeas(); i++)
		{
			std::cout << cat.getIdea(i) << std::endl;
		}

		dog.setIdea("Bark!");
		dog.setIdea("Play!");
		dog.setIdea("Eat!");
		std::cout << "\ndogs' ideas:" << dog.countIdeas() << std::endl;
		for (int i = 0; i < dog.countIdeas(); i++)
		{
			std::cout << dog.getIdea(i) << std::endl;
		}
		std::cout << std::endl;

		Cat		catCopy(cat);
		Dog		dogCopy(dog);

		catCopy.setIdea("Knock over glass of water");
		for (int i = 0; i < 98; i++)
		{
			dogCopy.setIdea("Squirrel!");
		}

		std::cout << "\ncats' ideas:" << cat.countIdeas() << std::endl;
		for (int i = 0; i < cat.countIdeas(); i++)
		{
			std::cout << cat.getIdea(i) << std::endl;
		}
		std::cout << "\ndogs' ideas:" << dog.countIdeas() << std::endl;
		for (int i = 0; i < dog.countIdeas(); i++)
		{
			std::cout << dog.getIdea(i) << std::endl;
		}
		std::cout << "\ncatCopys' ideas: "  << catCopy.countIdeas() << std::endl;
		for (int i = 0; i < catCopy.countIdeas(); i++)
		{
			std::cout << catCopy.getIdea(i) << std::endl;
		}
		std::cout << "\ndogCopys' ideas:" << dogCopy.countIdeas() << std::endl;
		for (int i = 0; i < dogCopy.countIdeas(); i++)
		{
			std::cout << dogCopy.getIdea(i) << std::endl;
		}
		std::cout << std::endl;

		const Animal* animalCat = new Cat();
		const Animal* animalDog = new Dog();

		std::cout << "\nanimalCats' ideas:" << animalCat->countIdeas() << std::endl;
		for (int i = 0; i < animalCat->countIdeas(); i++)
		{
			std::cout << animalCat->getIdea(i) << std::endl;
		}
		std::cout << "\nanimalDogs' ideas:" << animalDog->countIdeas() << std::endl;
		for (int i = 0; i < animalDog->countIdeas(); i++)
		{
			std::cout << animalDog->getIdea(i) << std::endl;
		}
		std::cout << std::endl;

		delete animalCat;
		delete animalDog;
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
