/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:30:18 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/04 10:21:47 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constructor for ScavTrap, which is derived from the ClapTrap */
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

/* Copy constructor.
/* It initializes the base class part of the new ScavTrap object by copying the base class
part of the other object. */
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap copy constructor called for " << this->_name << "!" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap assignment operator called for " << this->_name << "!" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed!" << std::endl;
}

/* Overriding the attack method */
void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " has no energy or hit points left to attack!" << std::endl;
	}
}

/* Special function */
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!" << std::endl;
}