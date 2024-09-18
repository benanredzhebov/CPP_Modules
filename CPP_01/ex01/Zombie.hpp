/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:08:01 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/18 08:09:02 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	_name;
	
	public:
		/* Constructor*/
		Zombie();

		/* Destructor */
		~Zombie();
		
		/*Set the zombie's name (for after allocation)*/
		void	setName(std::string name);

		/*Member function*/
		void	announce() const;
};

Zombie* zombieHorde( int N, std::string name );

#endif
