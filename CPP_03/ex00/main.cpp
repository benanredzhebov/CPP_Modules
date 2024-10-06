/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:45:36 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/06 21:51:29 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int	main(void)
{
	ClapTrap	robot("robot");
	ClapTrap	human("human");

	// Set robot's attack damage to 2
	robot.setAttackDamage(1);

	// Robot attacks human until it runs out of energy points
	for (int i = 0; i <= 10; i++) {
		if (robot.getEnergyPoints() > 0)
			robot.attack("human");
		else {
			std::cout << "Robot has no energy left to attack!" << std::endl;
			break;
		}
	}
	std::cout << "Robot attack damage: " << robot.getAttackDamage() << std::endl;

	// Human attacks robot
	human.attack("robot");

	// Human takes damage 3 times (check if human can take damage)
	for (int i = 0; i < 3; i++)
	{
		if (human.getHitPoints() > 0) {
			human.takeDamage(2);
			std::cout << "Human hit points after damage: " << human.getHitPoints() << std::endl;
		} else {
			std::cout << "Human has no hit points left!" << std::endl;
			break;
		}
	}

	// Human repairs itself
	human.beRepaired(5);
	std::cout << "Human hit points after repair: " << human.getHitPoints() << std::endl;
	std::cout << "Human energy points after repair: " << human.getEnergyPoints() << std::endl;

	return 0;
}