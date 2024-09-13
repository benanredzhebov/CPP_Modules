/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:56:12 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/13 16:33:30 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_APP

#include "./Weapon.hpp"

class HumanA {
	private:
	std::string	_name;
	Weapon&		_weapon; // HumanA always has a weapon, passed by reference

	public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	/* Attack (member)function */
	void		attack() const;
};

#endif