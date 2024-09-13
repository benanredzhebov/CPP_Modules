/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:42:41 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/13 10:11:46 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

/*crates a horde of N zombies using the zombieHorde function.
It then iterates through the nord, calling the announce method
on each zombie to print a message*/
int	main() {
	int	N = 10;
	Zombie* horde = zombieHorde(N, "ZombieHorde");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}