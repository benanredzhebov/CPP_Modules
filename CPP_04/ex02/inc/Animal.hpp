/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:09:18 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/10 12:04:23 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
	protected: //Allows derived classes to access the _type member directly, while preventing access from outside the class hierarchy.
	std::string _type;

	public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(AAnimal const &other);
	virtual ~AAnimal(); // Prevents resource leaks and undefined behavior when dealing with polymorphic objects.

	AAnimal			&operator=(const AAnimal &other);
	virtual void	makeSound() const = 0; // Pure virtual function
	std::string		getType() const;
};

#endif



/*The polymorphism in this example comes from the fact that the base class Animal
has a virtual method (makeSound()), which is overridden by the derived classes (Dog and Cat).
When we use pointers or references to the base class (Animal) to call this method, the program
dynamically calls the correct method for the actual object type (either Dog or Cat), not the
base class method.*/