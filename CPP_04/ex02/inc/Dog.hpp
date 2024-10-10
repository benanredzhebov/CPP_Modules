/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:33:41 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/10 12:05:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public AAnimal {
	private:
	Brain* _brain;
	
	public:
	Dog();
	Dog(const Dog &other);
	~Dog();
	
	Dog		&operator=(const Dog &other);   
	void	makeSound() const;
	void		setIdeas(int index, std::string idea);
	std::string	getIdeas(int index);
};

#endif
