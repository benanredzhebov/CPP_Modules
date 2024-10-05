/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:44:20 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/05 13:35:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), _name(name) // Initialize ClapTrap name with
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "Diamond copy constructor called.\n";
	*this = other;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
	if (this == &other)
		return *this;
	this->_name = other.getName();
	this->_hitPoints = other.FragTrap::getHitPoints();
	this->_energyPoints = other.ScavTrap::getEnergyPoints();
	this->_attackDamage = other.FragTrap::getAttackDamage();
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << "destroyed." << std::endl;
}

/*Overriding the attack function from ScavTrap */
void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target); //Use ScavTrap's atack method
}

void	DiamondTrap::whoAmI() {
	std::cout << "Diamontrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getDiamondName() {
	return this->_name;
}

void	DiamondTrap::setDiamondName(std::string name) {
	this->_name = name;
}

