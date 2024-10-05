/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:45:36 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/05 12:12:02 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

// int main() {
//     FragTrap frag("Fraggy");

//     frag.attack("target");
//     frag.highFivesGuys();
//     frag.takeDamage(20);
//     frag.beRepaired(10);

//     return 0;
// }

int	main(void)
{
	std::string partition(50, '-');

	std::cout << partition << std::endl;
	std::cout << "SCAVTRAP\n";
	std::cout << partition << std::endl;

	ScavTrap	scav("scav");
	scav.attack("clappy");
	scav.takeDamage(1);
	scav.guardGate();
	std::cout << "Energy points after took damage: " << scav.getEnergyPoints() << std::endl;
	std::cout << "Hit points before repaired " << scav.getHitPoints() << std::endl;
	scav.beRepaired(23);
	std::cout << "Hit points after repaired " << scav.getHitPoints() << std::endl;
	std::cout << "Scav energy points: " << scav.getEnergyPoints() << std::endl;

	std::cout << partition << std::endl;
	std::cout << "FRAGTRAP\n";
	std::cout << partition << std::endl;
	
	FragTrap frog("frog");
	frog.highFivesGuys();
	std::cout << "name: " << frog.getName() << std::endl;
	std::cout << "Frag attack damage: " << frog.getAttackDamage() << std::endl;
	frog.attack("robot");
	frog.getAttackDamage();
	
	FragTrap fraggy("fraggy");
	fraggy.highFivesGuys();
	std::cout << "Energy points after took damage: " << scav.getEnergyPoints() << std::endl;
	std::cout << "Hit points before repaired " << scav.getHitPoints() << std::endl;
	scav.beRepaired(12);
	std::cout << "Hit points after repaired " << scav.getHitPoints() << std::endl;
	std::cout << "Scav energy points: " << scav.getEnergyPoints() << std::endl;
	std::cout << partition << std::endl;
	std::cout << partition << std::endl;

	return 0;
}