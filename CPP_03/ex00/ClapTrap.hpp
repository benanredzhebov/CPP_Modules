/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:03:31 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/06 21:40:54 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string			_name;
		unsigned int		_hitPoints; // Health of ClapTrap, starts at 10
		unsigned int		_energyPoints;
		unsigned int		_attackDamage; // Damage dealt in attacks, starts at 0

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		~ClapTrap();

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		void				setAttackDamage(unsigned int attack_damage);
		unsigned int		getAttackDamage(void) const;

		//Getter methods to access private members
		unsigned int		getHitPoints() const;
		unsigned int		getEnergyPoints() const;
		const std::string&	getName() const;
		
};

#endif