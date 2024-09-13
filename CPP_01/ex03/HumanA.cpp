/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:05:54 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/13 15:19:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"
#include "./Weapon.hpp"

/* Constructor that initializes the human with a name and weapon reference */
HumanA::HumanA(std::string name, Weapon& weapon)
			: _name(name), _weapon(weapon) {}

HumanA::~HumanA(){}

/* Member functions attack() that displays message */
void	HumanA::attack() const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}