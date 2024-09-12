/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:53:11 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/12 12:10:41 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie {
	private:
		std::string	_name;
	public:
		Zombie ( std::string name ); //Constructor declaration
		~Zombie ( void ); //Destructor declaration

		void	announce(void);
};

#endif