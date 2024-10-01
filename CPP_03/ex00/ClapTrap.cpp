/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:18:02 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/01 15:25:44 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

// Attack
void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy or hit points to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " point of damage!" << std::endl;
}

// Take Damage(applies damage to the ClapTrap)
void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and is now destroyed!" << std::endl;
	}
	else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
	}
}

//Be repaired. If no ClapTrap no energy or hit points, it cannot repair itself
void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy or hit points to repair!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself, restoring " << amount << " hit points!" << std::endl;
}

void	ClapTrap::setAttackDamage(unsigned int attack_damage) {
	this->_attackDamage = attack_damage;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

unsigned int	ClapTrap::getHitPoints() const {
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

const std::string& ClapTrap::getName() const {
	return _name;
}