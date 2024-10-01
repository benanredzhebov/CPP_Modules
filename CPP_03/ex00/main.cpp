/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:45:36 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/01 15:14:40 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

// int	main() {
// 	ClapTrap robot("robot");
	
// 	robot.attack("target1");
// 	robot.takeDamage(5);
// 	robot.beRepaired(3);
// 	robot.attack("target2");
// 	robot.takeDamage(10);
// 	robot.beRepaired(5);

// 	return 0;
// }

// int main() {
//     ClapTrap robot("robot");

//     // Keep attacking target1 until the robot runs out of energy points or hit points
//     std::string target = "target1";

//     while (robot.getHitPoints() > 0 && robot.getEnergyPoints() > 0) {
//         robot.attack(target);
//     }

//     std::cout << "ClapTrap " << robot.getName() << " cannot continue attacking. No more energy or hit points!" << std::endl;

//     // Damage and repair operations to further test the behavior
//     robot.takeDamage(5);          // Take 5 points of damage
//     robot.beRepaired(3);          // Repair 3 hit points
//     robot.takeDamage(10);         // Take 10 points of damage, likely destroying the ClapTrap

//     return 0;
// }

// int	main(void)
// {
// 	ClapTrap	robot("robot");
// 	ClapTrap	human("human");

// 	robot.setAttackDamage(2);
// 	for (int i = 0; i < 11; i++)
// 		robot.attack("human");
// 	std::cout << "Clap attack damage: " << robot.getAttackDamage() << std::endl;
// 	human.attack("robot");
// 	for (int i = 0; i < 3; i++)
// 	{
// 		human.takeDamage(2);
// 		std::cout << "Trap hit point: " << human.getHitPoints() << std::endl;
// 	}
// 	human.beRepaired(5);
// 	std::cout << "Trap hit point: " << human.getHitPoints() << std::endl;
// 	std::cout << "Trap energy point: " << human.getEnergyPoints() << std::endl;
// }

int	main(void)
{
	ClapTrap	robot("robot");
	ClapTrap	human("human");

	// Set robot's attack damage to 2
	robot.setAttackDamage(1);

	// Robot attacks human until it runs out of energy points
	for (int i = 0; i < 11; i++) {
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