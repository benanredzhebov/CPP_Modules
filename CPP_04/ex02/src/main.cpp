/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:18:50 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 10:48:12 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

void testAnimalArray() {
	const int numAnimals = 4;
	AAnimal* animals[numAnimals];
	// AAnimal animal();

	for (int i = 0; i < numAnimals / 2; ++i) {
		animals[i] = new Cat();
	}
	for (int i = numAnimals / 2; i < numAnimals; ++i) {
		animals[i] = new Dog();
	}

	for (int i = 0; i < numAnimals; ++i) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < numAnimals; ++i) {
		delete animals[i];
	}
}

int main() {
	std::cout << "Testing Animal Array:" << std::endl;
	testAnimalArray();
	return 0;
}

// int main()
// {
// 	std::string partition(50, '-');

// 	// AAnimal animal(); // Animal class can no longer be instantiated

// 	std::cout << partition << std::endl;
// 	std::cout << "ANIMAL ARRAY\n";
// 	std::cout << partition << std::endl;
// 	{
// 		AAnimal *animals[4];
// 		animals[0] = new Cat();
// 		animals[1] = new Dog();
// 		animals[2] = new Cat();
// 		animals[3] = new Dog();
// 		for (int i = 0; i < 4; i++)
// 			animals[i]->makeSound();
// 		for (int i = 0; i < 4; i++)
// 			delete animals[i];
// 	}

// 	std::cout << partition << std::endl;
// 	std::cout << "CAT BRAIN\n";
// 	std::cout << partition << std::endl;
// 	{
// 		Cat cat;
// 		cat.setIdeas(34, "loud");
// 		std::cout << cat.getIdeas(34) << std::endl;
// 		for (int i = 0; i < 50; i++)
// 			cat.setIdeas(i, "no clue");
// 		Cat bluecat(cat);
// 		for (int i = 0; i < 100; i++)
// 			std::cout << bluecat.getIdeas(i) << std::endl;

// 		bluecat.setIdeas(6, "newthings");
// 		std::cout << "Bluecat: " << bluecat.getIdeas(6) << std::endl;
// 		std::cout << "Cat: " << cat.getIdeas(6) << std::endl;
// 	}

// 	std::cout << partition << std::endl;
// 	std::cout << "DOG BRAIN\n";
// 	std::cout << partition << std::endl;
// 	{
// 		Dog dog;
// 		dog.setIdeas(69, "eat.sleep.repeat");
// 		std::cout << dog.getIdeas(69) << std::endl;
// 		for (int i = 0; i < 50; i++)
// 			dog.setIdeas(i, "no brainer");
// 		Dog dawg(dog);
// 		for (int i = 0; i < 100; i++)
// 			std::cout << dawg.getIdeas(i) << std::endl;
// 		dawg.setIdeas(6, "run");
// 		std::cout << "dawg: " << dawg.getIdeas(6) << std::endl;
// 		std::cout << "dog: " << dog.getIdeas(6) << std::endl;
// 		dog.setIdeas(101, "ad");
// 		dog.getIdeas(101);
// 	}
// }