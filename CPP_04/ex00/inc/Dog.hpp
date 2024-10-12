/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:33:41 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 08:26:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"

class Dog : public Animal {
	public:
	Dog();
	Dog(const Dog &other);
	virtual ~Dog();
	
	Dog		&operator=(const Dog &other);
	void	makeSound() const;
};

#endif
