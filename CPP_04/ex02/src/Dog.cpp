/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:36:22 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 13:33:10 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called!" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog::~Dog() {
	std::cout << "Dog destructor called!" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other); //calls the assignment operator of the base class (AAnimal), ensuring that the base class portion of the object is correctly assigned.
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
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