/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:45:36 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/01 09:48:45 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int	main() {
	ClapTrap robot("Clappy");
	
	robot.attack("target1");
	robot.takeDamage(5);
	robot.beRepaired(3);
	robot.attack("target2");
	robot.takeDamage(10);
	robot.beRepaired(5);

	return 0;
}