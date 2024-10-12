/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:36:22 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 10:10:21 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called\n";
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain); // Deep copy of the Brain object
}

Dog::~Dog() {
	std::cout << "Dog destructor called!" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other); //calls the assignment operator of the base class (Animal), ensuring that the base class portion of the object is correctly assigned.
		this->_brain = new Brain(*other._brain); // Deep copy of the Brain object
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

void	Dog::setIdeas(int index, std::string idea) {
	this->_brain->setIdeas(index, idea);
}

std::string	Dog::getIdeas(int index) {
	return this->_brain->getIdeas(index);
}