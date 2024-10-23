/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:29:55 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/23 14:39:24 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"
#include "./Data.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

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
