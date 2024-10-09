/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:36:22 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/09 10:46:02 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    *this = other;
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