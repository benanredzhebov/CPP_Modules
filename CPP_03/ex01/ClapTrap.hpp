/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:03:31 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/04 09:09:57 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string	_name;
		int			_hitPoints; // Health of ClapTrap, starts at 10
		int			_energyPoints;
		int			_attackDamage; // Damage dealt in attacks, starts at 0

	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		//Getter methods to access private members
		// unsigned int		getHitPoints() const;
		unsigned int		getEnergyPoints() const;
		// const std::string&	getName() const;
		// unsigned int		getAttackDamage(void) const;
		// void				setAttackDamage(unsigned int attack_damage);
		
};

#endif