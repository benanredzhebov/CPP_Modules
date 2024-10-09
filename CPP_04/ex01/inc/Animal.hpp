/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:09:18 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/09 11:37:20 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected: //Allows derived classes to access the _type member directly, while preventing access from outside the class hierarchy.
	std::string _type;

	public:
	Animal();
	Animal(std::string type);
	Animal(Animal const &other);
	virtual ~Animal(); // Prevents resource leaks and undefined behavior when dealing with polymorphic objects.

	Animal			&operator=(const Animal &other);
	virtual void	makeSound() const; //Allows derived classes to override this function to provide specific implementations.
	std::string		getType() const;
};

#endif



/*The polymorphism in this example comes from the fact that the base class Animal
has a virtual method (makeSound()), which is overridden by the derived classes (Dog and Cat).
When we use pointers or references to the base class (Animal) to call this method, the program
dynamically calls the correct method for the actual object type (either Dog or Cat), not the
base class method.*/