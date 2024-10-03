/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:30:18 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/03 17:58:29 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constructor */
ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

/* Overriding the attack method */
void ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target
				  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
	}
}

/* Special function */
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode!" << std::endl;
}