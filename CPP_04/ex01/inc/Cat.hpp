/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:12:10 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/10 09:55:39 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal {
	private:
	Brain* _brain;
	
	public:
	Cat();
	Cat(const Cat &other);
	virtual ~Cat();
	
	Cat		&operator=(const Cat &other);
	void	makeSound() const;
	void		setIdeas(int index, std::string idea);
	std::string	getIdeas(int index);
};

#endif