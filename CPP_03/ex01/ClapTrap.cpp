/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:18:02 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/03 18:10:34 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(std::string _name) : _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap copy constructor called for " << _name << "!" << std::endl;
}

// Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap assignment operator called for " << _name << "!" << std::endl;
    return *this;
}

// Attack function
void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        this->_energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
    }
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount) {
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0) this->_hitPoints = 0;
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
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
