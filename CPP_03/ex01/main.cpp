/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:45:36 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/03 18:12:12 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int main(void) {
    ClapTrap robot("robot");
    ScavTrap scav("scav");

    robot.attack("enemy");
    scav.attack("intruder");

    scav.guardGate();
    
    return 0;
}