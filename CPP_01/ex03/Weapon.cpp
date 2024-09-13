/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:36:47 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/13 15:13:39 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

/* Construction to initialize the weapon type
_type = type */

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon ( void ) {}

/* Getter to return  a const reference to the weapon type*/
const std::string& Weapon::getType() const {
	return _type;
}

/* Setter to modify the weapon type */
void	Weapon::setType(std::string type) {
	_type = type;
}
