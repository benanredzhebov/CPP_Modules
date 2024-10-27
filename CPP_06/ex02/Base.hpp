/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:34:45 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/27 18:02:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {

	public:
		virtual ~Base() {};

};

Base	*generate(void);
void	identify(Base *ptr);
void	identify(Base &ptr);

#endif








/*Polymorphism and Dynamic Binding:

When you have a base class with virtual functions, you often use pointers or references
to the base class to refer to derived class objects. This is known as polymorphism.
If you delete a derived class object through a base class pointer, the base class
destructor must be virtual to ensure that the derived class destructor is called
 This ensures proper cleanup of resources allocated by the derived class.*/