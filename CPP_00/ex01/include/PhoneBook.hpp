/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:26:39 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/09/03 16:41:11 by beredzhe         ###   ########.fr       */
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
	Contact contacts[8];
	std::string userInput;
	int		entry;
	void	putContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	void	replaceOldestContact();
	bool	displayExtract(void);
	bool	displayData(std::string user_input);

public:
	PhoneBook(void);
	~PhoneBook(void);

	int		getInfo(void);
	int		searchEntries(void);
	void	showInstruction(void);
};

#endif