/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:28:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 10:25:27 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

AAnimal::AAnimal() : _type("Default Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "Animal constructor with type called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) {
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return *this;
}

// void AAnimal::makeSound() const {
// 	std::cout << "Animal sound!" << std::endl; //abstract member function needs no definition
// }

std::string AAnimal::getType() const {
	return this->_type;
}