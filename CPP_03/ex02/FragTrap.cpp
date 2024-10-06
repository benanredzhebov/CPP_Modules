/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:11:57 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/06 22:30:15 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << this->_name << " has been copy-constructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap " << this->_name << " has been assigned!" << std::endl;
	}
	return *this;
}


FragTrap::~FragTrap () {
	std::cout << "FragTrap " << this->_name << " has been destroyed!" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " has no energy or hit points left to attack!" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " requests high fives from everyone!" << std::endl;
}