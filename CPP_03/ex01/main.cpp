/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:45:36 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/04 09:13:16 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

// int main() {
//     ScavTrap scav("Scavvy");

//     scav.attack("target");
//     scav.guardGate();
//     scav.takeDamage(20);
//     scav.beRepaired(10);
    
//     return 0;
// }

int	main(void)
{
	std::string partition(50, '-');

	std::cout << partition << std::endl;
	std::cout << "CLAPTRAP\n";
	std::cout << partition << std::endl;

	{
		ClapTrap	robot("robot");
		robot.attack("scav");
	}

	std::cout << partition << std::endl;
	std::cout << "SCAVTRAP\n";
	std::cout << partition << std::endl;

	ScavTrap	scav("scav");
	scav.attack("robot");
	scav.takeDamage(1);
	scav.guardGate();
	scav.beRepaired(23);
	std::cout << "Scav energy points: " << scav.getEnergyPoints() << std::endl;

	std::cout << partition << std::endl;
	std::cout << partition << std::endl;
	ScavTrap scav2(scav);
	scav.attack("robot");
	scav.takeDamage(1);
	scav.guardGate();
	scav.beRepaired(23);
	std::cout << "Scav energy points: " << scav.getEnergyPoints() << std::endl;
	std::cout << partition << std::endl;
	std::cout << partition << std::endl;
}