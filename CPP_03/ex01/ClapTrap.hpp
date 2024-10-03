/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:03:31 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/03 17:48:31 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string	_name;
		int			_hitPoints; // Healt of ClapTrap, starts at 10
		int			_energyPoints;
		int			_attackDamage; // Damage dealt in attacks, starts at 0

	public:
		ClapTrap(std::string _name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		//Getter methods to access private members
		unsigned int		getHitPoints() const;
		unsigned int		getEnergyPoints() const;
		const std::string&	getName() const;
		unsigned int		getAttackDamage(void) const;
		void				setAttackDamage(unsigned int attack_damage);
		
};

#endif