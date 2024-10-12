/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:18:50 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 10:05:49 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

#include <iostream>
#include <string>

// Test polymorphism and dynamic memory management.

void testAnimalArray() {
	Animal *animals[4];
	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();

	for (int i = 0; i < 4; i++)
		animals[i]->makeSound(); //The makeSound method is called on each Animal pointer. Due to polymorphism, the correct makeSound method for Cat or Dog is called.

	for (int i = 0; i < 4; i++)
		delete animals[i];
}

// Test the Cat class's ability to manage ideas and verify deep copying.

void testCatBrain() {
	Cat cat;
	cat.setIdeas(34, "loud");
	std::cout << "34: " << cat.getIdeas(34) << std::endl;

	//Set multiple ideas in a loop
	for (int i = 0; i < 50; i++)
		cat.setIdeas(i, "no clue");

	Cat bluecat(cat);  // Copy constructor

	//Print all ideas from the copied object to verify deep copying.
	for (int i = 0; i < 100; i++)
		std::cout << i << ": "<< bluecat.getIdeas(i) << std::endl;

	bluecat.setIdeas(6, "newthings");
	std::cout << "Bluecat: " << 6 << ": " << bluecat.getIdeas(6) << std::endl;
	std::cout << "Cat: " << 6 << ": " << cat.getIdeas(6) << std::endl;
}

// Test the Dog class's ability to manage ideas and verify deep copying.

void testDogBrain() {
	Dog dog;
	dog.setIdeas(69, "eat.sleep.repeat");
	std::cout << "69: " << dog.getIdeas(69) << std::endl;

	for (int i = 0; i < 50; i++)
		dog.setIdeas(i, "no brainer");

	Dog dawg(dog);  // Copy constructor

	for (int i = 0; i < 100; i++)
		std::cout << i << ": " << dawg.getIdeas(i) << std::endl;

	dawg.setIdeas(6, "run");
	std::cout << "Dawg: " << 6 << ": " << dawg.getIdeas(6) << std::endl; // Since the dog object's brain was not modified at index 6 after the copy, it still holds "no brainer".
	std::cout << "Dog: " << 6 << ": " << dog.getIdeas(6) << std::endl;

	dog.setIdeas(101, "ad");
	dog.getIdeas(101);
}

int main() {
	std::string partition(50, '-');

	std::cout << partition << std::endl;
	std::cout << "ANIMAL ARRAY\n";
	std::cout << partition << std::endl;
	testAnimalArray();  // Call function to test the animal array

	std::cout << partition << std::endl;
	std::cout << "CAT BRAIN\n";
	std::cout << partition << std::endl;
	testCatBrain();  // Call function to test the cat brain

	std::cout << partition << std::endl;
	std::cout << "DOG BRAIN\n";
	std::cout << partition << std::endl;
	testDogBrain();  // Call function to test the dog brain
}
