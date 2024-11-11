/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:00:49 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/11 14:29:38 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float>	_exchangeRates;

		bool							_isValidDate(const std::string& date);
		bool							_isValidValue(const std::string& value);
		std::string						_getClosestDate(const std::string& date);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange &other);

		bool	loadDatabase(const std::string& filename);
		void	processInput(const std::string& filename);
	
};

#endif