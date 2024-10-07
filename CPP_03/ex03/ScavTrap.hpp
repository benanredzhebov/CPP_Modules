/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:55:01 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/07 14:51:45 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

/* declares new class that inherits from ClapTrap
By using virtual inheritance, I ensure that only
one instance of the base class (ClapTrap) is shared
among all derived classes.
This resolves the diamond problem by making sure that
ScavTrap and any other classes that might inherit from
ClapTrap through multiple paths will share a single instance of ClapTrap.*/
class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);
		void	attack(const std::string& target);
		void	guardGate();
};

#endif