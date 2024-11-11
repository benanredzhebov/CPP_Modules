/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:17:57 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/11 14:29:31 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
	if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".csv") {
		std::cerr << "Error: file must have a .csv extension." << std::endl;
		return false;
	}
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}

	std::string	line;
	//Reads the file line by line
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		float rate;
		if (std::getline(ss, date, ',') && ss >> rate) {
			_exchangeRates[date] = rate;
			// std::cout << "DEBUG. Loaded: " << date << " => " << rate << std::endl;
		}
	}

	file.close();
	return true;
}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, valueStr;
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
			date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);
			valueStr = valueStr.substr(valueStr.find_first_not_of(" \t\n\r\f\v"));

			if (!_isValidDate(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}

			if (!_isValidValue(valueStr)) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}

			float value = std::atof(valueStr.c_str());
			if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			std::string closestDate = _getClosestDate(date);
			float rate = _exchangeRates[closestDate];
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		}
	}

	file.close();
}

bool BitcoinExchange::_isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	// Check for valid days in each month
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
	}
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > 29 || (day == 29 && !isLeap)) {
			return false;
		}
	}

	return true;
}

bool BitcoinExchange::_isValidValue(const std::string& value) {
	if (value.empty()) {
		return false;
	}
	bool dotSeen = false;
	for (size_t i = 0; i < value.size(); ++i) {
		if (!std::isdigit(value[i])) {
			if (value[i] == '.' && !dotSeen) {
				dotSeen = true;
			} else {
				return false;
			}
		}
	}
	return true;
}

std::string BitcoinExchange::_getClosestDate(const std::string& date) {
	std::map<std::string, float>::iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.end() || it->first != date) {
		if (it == _exchangeRates.begin()) {
			return it->first;
		}
		--it;
	}
	return it->first;
}