/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:44:20 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/05 23:56:12 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("default name")
{
	std::cout << "Diamond constructor called" << std::endl;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), _name(name)
	// : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();

	std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "Diamond copy constructor called.\n";
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other.FragTrap::getHitPoints();
		this->_energyPoints = other.ScavTrap::getEnergyPoints();
		this->_attackDamage = other.FragTrap::getAttackDamage();
	}
	return *this;
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

/*Overriding the attack function from ScavTrap */
void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target); //Use ScavTrap's atack method
}