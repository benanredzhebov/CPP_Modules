/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:44:07 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/05 23:44:00 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(DiamondTrap const &other);
		~DiamondTrap();

		DiamondTrap	&operator=(DiamondTrap const &other);
		void whoAmI();
		void attack(const std::string& target);

		std::string getDiamondName();
		void		setDiamondName(std::string name);
};

#endif