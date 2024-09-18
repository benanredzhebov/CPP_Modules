/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:46:28 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/18 08:01:29 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main(void) {
	// Create a zombie on the heap
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	// Create a zombie on the stack
	randomChump("StackZombie");

	delete heapZombie;
}