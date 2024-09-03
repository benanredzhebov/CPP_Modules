/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:56:09 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/03 16:59:39 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->entry = -1;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::getInfo(void)
{
	int	i = 0;
	int	j;
	std::string	info[5];
}