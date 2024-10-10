/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:54:09 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/10 10:19:58 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea";
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

void	Brain::setIdeas(int index, std::string idea) {

	if (index < 0 || index > 99)
	{
		std::cout << "Error: index must be between 0 and 99!\n";
		return ;
	}
	this->_ideas[index] = idea;
}

std::string	Brain::getIdeas(int index) {

	if (index < 0 || index > 99)
	{
		std::cout << "Wrong index has to be between 0 and 99!\n";
		return "";
	}
	return this->_ideas[index];
}
