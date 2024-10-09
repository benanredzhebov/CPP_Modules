/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:12:10 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/09 10:24:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "./Animal.hpp"

class Cat : public Animal {
    public:
    Cat();
    // Cat(std::string type);
    Cat(const Cat& other);
    virtual ~Cat();
    
    Cat     &operator=(const Cat &other);
    void    makeSound() const;
};

#endif