/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:15:07 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 13:32:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	std::cout << "Brain copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		AAnimal::operator=(other); //calls the assignment operator of the base class (AAnimal), ensuring that the base class portion of the object is correctly assigned.
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

void	Cat::setIdeas(int index, std::string idea) {

	this->_brain->setIdeas(index, idea);
}

std::string	Cat::getIdeas(int index) {

	return this->_brain->getIdeas(index);
}