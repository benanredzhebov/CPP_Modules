/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:55:01 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/03 17:41:45 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string _name);
		~ScavTrap();

		/* Member function */
		void	attack(const std::string& target);
		void	guardGate();
};

#endif