/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:21:56 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/12 08:43:52 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &other);
	virtual ~WrongCat();

	WrongCat	&operator=(const WrongCat &other);
	void		makeSound() const;
};

#endif