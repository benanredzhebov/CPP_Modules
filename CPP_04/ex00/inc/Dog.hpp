/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:33:41 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/08 17:38:42 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG.HPP
#define DOG.HPP

#include "./Animal.hpp"

class Dog : public Animal {
    public:
    Dog();
    ~Dog();
    void    makeSound() const override; // Override the makeSound method
};

#endif
