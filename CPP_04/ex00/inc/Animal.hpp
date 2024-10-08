/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:09:18 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/08 17:31:47 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL.HPP
#define ANIMAL.HPP

#include <iostream>

class Animal {
    protected:
    std::string type;

    public:
    Animal();
    virtual ~Animal();

    virtual void    makeSound() const;
    std::string     getType() const;
};

#endif