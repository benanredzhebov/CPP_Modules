/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:55:01 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/06 22:00:50 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

/* declares new class that inherits from ClapTrap*/
class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();

		/* Member function */
		void	attack(const std::string& target);
		void	guardGate();
};

#endif