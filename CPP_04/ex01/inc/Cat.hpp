/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:12:10 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 10:16:53 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal {
	private:
	Brain* _brain; // encapsulation. It can be accessed directly from outside the class. It can only be accessed and modified through public methods
	
	public:
	Cat();
	Cat(const Cat &other);
	virtual ~Cat();
	
	Cat			&operator=(const Cat &other);
	void		makeSound() const;
	void		setIdeas(int index, std::string idea); // Allows setting an idea at a specific index in the _brain.
	std::string	getIdeas(int index); // Allows retrieving an idea from a specific index in the _brain.
};

#endif