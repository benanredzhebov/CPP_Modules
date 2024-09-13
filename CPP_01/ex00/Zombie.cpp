/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:03:44 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/13 10:01:54 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

/*The Zombie class has a consructor to initialize
the zombie's name, a destructor to announce when
the zombie is terminated, and a method to announce
the zombie's presence with a characteristic phrase.*/

Zombie::Zombie( std::string name ) : _name(name) {}

Zombie::~Zombie() {
	std::cout << this->_name << " is destroyed" << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}