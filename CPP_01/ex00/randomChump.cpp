/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:45:19 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/12 12:05:36 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

/*Creates a zombie on the stack and announces it*/
void	randomChump(std::string name) {
	Zombie stackZombie(name); // creates a Zombie object named stackZombie
	stackZombie.announce();
}