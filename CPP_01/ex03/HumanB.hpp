/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:35:25 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/13 16:43:07 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "./Weapon.hpp"

class HumanB {
	private:
	std::string	_name;
	Weapon* _weapon; // HumanB may or may not have a weapon, so we use a pointer

	public:
	HumanB(std::string name);
	~HumanB();

	/* Set weapon function*/
	void	setWeapon(Weapon& weapon);
	void	attack() const;
};

#endif