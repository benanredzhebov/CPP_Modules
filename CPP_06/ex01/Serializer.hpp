/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:19:38 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/26 09:23:40 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h> //for uintptr_t

struct Data; // Forward declaration of Data class

class Serializer {
	public:
		static uintptr_t	serialize(Data* ptr); // It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static Data*		deserialize(uintptr_t raw); // It takes an unsigned integer parameter and converts it to a pointer to Data

	/* The constructor, destructor, copy constructor, and copy assignment
	operator of the Serializer class are private to prevent instantiation and copying of the class.
	This design choice is made because the Serializer class is intended to be used only through its static methods. */
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
};

#endif