/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:46:28 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/12 13:34:27 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"


Zombie* newZombie(std::string name); // Returns pointer to Zombie object allocated with new.
void	randomChump(std::string name); // Creates new Zombie stored on the heap, which announces itself.

int	main(void) {
	// Create a zombie on the heap
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	// Create a zombie on the stack
	randomChump("StackZombie");

	delete heapZombie;
}