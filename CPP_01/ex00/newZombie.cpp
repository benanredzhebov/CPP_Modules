/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:43:08 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/12 10:57:07 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

/*This function creates a zombie dynamically on the heap.
I need to remember to delete it.*/
Zombie*	newZombie(std::string name) {
	Zombie* zombie = new Zombie(name);
	return (zombie);
	// return new Zombie(name); //shorter variant to write it our
}