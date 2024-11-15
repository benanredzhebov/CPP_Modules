/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:00:49 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/14 13:49:59 by beredzhe         ###   ########.fr       */
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
#include <iomanip>
#include <cmath>

class BitcoinExchange {
	private:
		std::map<std::string, float>	_exchangeRates; //his container is used to store the exchange rates with the date as the key and the rate as the value. It is referenced as _exchangeRates.

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


/*std::map elements are sorted by their keys in ascending order by default. This makes maps useful for ordered data retrieval.*/