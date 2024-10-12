/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:36:22 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 08:35:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	std::cout << "Dog constructor called!" << std::endl;
}

/*It initilizes the base class part of the Dog object by
calling the copy constructor of the Animal class. This
ensures that all the base class members are properly
copietd from the other object */
Dog::Dog(const Dog &other) : Animal(other) {
	*this = other; // all the members of the Dog class including those inherited from Animal class are copied correctly.
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}