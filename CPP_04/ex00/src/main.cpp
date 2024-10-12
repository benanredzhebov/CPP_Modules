/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:18:50 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 08:32:53 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() {
const Animal* meta = new Animal(); //meta is a pointer to an Animal object
const Animal* j = new Dog(); // j is a pointer to a Dog, but it is declared as a pointer to Animal(polymorphism)
const Animal* i = new Cat(); // i is a pointer to a Cat, but it is declared as a pointer to Animal(polymorphism)
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();

/* Testing WrongAnimal and WrongCat*/
const WrongAnimal* wrong = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();

wrongCat->makeSound();

delete meta;
delete j;
delete i;
delete wrong;
delete wrongCat;

return 0;
}


/*If makeSound() were not declared as virtual in Animal.hpp.
hen, calling i->makeSound() or j->makeSound() would always call Animal's makeSound() method,
which outputs "Unknown animal sound!", regardless of whether i points to a Cat or Dog*/

// int main()
// {
// 	std::string partition(50, '-');

// 	std::cout << partition << std::endl;
// 	std::cout << "ANIMAL\n";
// 	std::cout << partition << std::endl;

// 	{
// 		const Animal* meta = new Animal();
// 		const Animal* dog = new Dog();
// 		const Animal* cat = new Cat();
// 		std::cout << dog->getType() << " " << std::endl;
// 		std::cout << cat->getType() << " " << std::endl; 
// 		dog->makeSound(); //will output the dog sound!
// 		cat->makeSound();
// 		meta->makeSound();
// 		delete meta;
// 		delete dog;
// 		delete cat;
// 	}

// 	std::cout << partition << std::endl;
// 	std::cout << "WRONGANIMAL\n";
// 	std::cout << partition << std::endl;

// 	{
// 		const WrongAnimal* meta = new WrongAnimal();
// 		const WrongAnimal* cat = new WrongCat();
// 		std::cout << cat->getType() << " " << std::endl; 
// 		cat->makeSound();
// 		meta->makeSound();
// 		delete meta;
// 		delete cat;
// 	}

// 	return 0;

// }