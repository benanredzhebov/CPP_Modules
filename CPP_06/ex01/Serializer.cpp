/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:29:55 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/26 08:41:50 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"
#include "./Data.hpp"

/* Converts a pointer to a Data object into an
unsigned integer (uintptr_t). reinterpret_cast - pointer->integer type*/
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

/* Converts an unsigned integer back into a pointer to
a Data object.*/
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &other) {
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return *this;
}
