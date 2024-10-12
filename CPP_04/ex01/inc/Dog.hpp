/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:33:41 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 10:17:46 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal {
	private:
	Brain* _brain; // Encapsulation. It can be accessed directly from outside the class. It can only be accessed and modified through public methods
	
	public:
	Dog();
	Dog(const Dog &other);
	virtual ~Dog();
	
	Dog			&operator=(const Dog &other);
	void		makeSound() const;
	void		setIdeas(int index, std::string idea); // Allows setting an idea at a specific index in the _brain.
	std::string	getIdeas(int index); // // Allows retrieving an idea from a specific index in the _brain.
};

#endif
