/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:03:31 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/01 10:13:11 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hitPoints; // Healt of ClapTrap, starts at 10
		unsigned int	_energyPoints;
		unsigned int	_attackDamage; // Damage dealt in attacks, starts at 0

	public:
		ClapTrap(const std::string& name);
		~ClapTrap();

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif