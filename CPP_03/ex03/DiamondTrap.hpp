/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:44:07 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/05 13:26:32 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string _name;
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &other);
		DiamondTrap	&operator=(DiamondTrap const &other);
		~DiamondTrap();

		void whoAmI();
		void attack(const std::string& target);

		std::string getDiamondName();
		void		setDiamondName(std::string name);
};

#endif