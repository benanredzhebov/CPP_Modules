/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:30:18 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/05 23:55:23 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap () {

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Scav constructor called" << std::endl;
}

/* Constructor for ScavTrap, which is derived from the ClapTrap */
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

/* Copy constructor.
It initializes the base class part of the new ScavTrap object by copying the base class
part of the other object. */
ScavTrap::ScavTrap (ScavTrap const &scav) : ClapTrap(scav) {
	*this = scav;  // This invokes the assignment operator!
	std::cout << "Scav copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " has been destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scav) {
	if (this != &scav) {
		this->_name = scav.getName();
		this->_hitPoints = scav.getHitPoints();
		this->_energyPoints = scav.getEnergyPoints();
		this->_attackDamage = scav.getAttackDamage();
	}
	return *this;
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