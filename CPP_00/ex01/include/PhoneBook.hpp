/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:26:39 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/09/05 17:07:32 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include "./Contact.hpp"

class PhoneBook
{
private:
	Contact		contacts[8];
	std::string	_userInput;
	int			_entry;
	void		_putContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	void		_replaceOldestContact();
	bool		_displayExtract(void);
	bool		_displayData(std::string user_input);

public:
	PhoneBook(void);
	~PhoneBook(void);

	int		getInfo(void);
	int		searchEntries(void);
	void	showInstruction(void);
};

#endif