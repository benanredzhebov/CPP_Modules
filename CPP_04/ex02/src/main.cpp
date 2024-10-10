/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:18:50 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/10 12:10:23 by beredzhe         ###   ########.fr       */
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