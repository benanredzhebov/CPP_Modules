/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:17:57 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/14 13:45:20 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeRates(other._exchangeRates) {
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

/*Load data from a CSV file.*/
bool BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str()); // is using for reading the data from files.
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}

	std::string	line;
	//Reads the file line by line. Extracts the date and exchange rate
	while (std::getline(file, line)) {
		std::istringstream ss(line); // Create an input string stream object initialized with the current line
		std::string date;
		float rate;
		/*Reads the date from the stream and stores it in the date variable. It stops reading when it encounters the comma (',').*/
		if (std::getline(ss, date, ',') && ss >> rate) { //ss >> rate reads the float value from the remaining part of the string into rate
			_exchangeRates[date] = rate; // Store the date and rate in the map
		}
	}

	file.close();
	return true;
}

/* Processes an input file containing date-value pairs. It performs several validations*/
void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	// Check the first line for header
	std::string firstLine;
	if (!std::getline(file, firstLine) || firstLine != "date | value") {
		std::cerr << "First line must be 'date | value'." << std::endl;
		return;
	}

	// Check if file is empty after the header
	std::string line;
	if (!std::getline(file, line)) {
		std::cerr << "Error: input file is empty." << std::endl;
		return;
	}
	file.seekg(0, std::ios::beg); // Reset file read position to the start of data after header

	// Skip the header and start processing data lines
	std::getline(file, line); //first line

	while (std::getline(file, line)) {
		std::istringstream ss(line); // allowing easy extraction of the date and value
		std::string date, valueStr;

		// Split line by '|'
		if (std::getline(ss, date, '|')) {
			// Trim whitespace from date
			date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);

			// Check if date is valid
			if (!_isValidDate(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}

			// Check if there is a value part after the '|'
			if (!std::getline(ss, valueStr)) {
				// No value after pipe (empty or malformed)
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			// Trim whitespace from valueStr
			valueStr = valueStr.substr(valueStr.find_first_not_of(" \t\n\r\f\v"));

			// Validate value
			if (!_isValidValue(valueStr)) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}

			// Convert value to float and check range
			float value = std::atof(valueStr.c_str());
			if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			// Find closest exchange rate and calculate result
			std::string closestDate = _getClosestDate(date);
			float rate = _exchangeRates[closestDate];
			std::cout << std::fixed << std::setprecision(2);
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		} else {
			// If no pipe is found or malformed line
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}

	file.close();
}

bool BitcoinExchange::_isValidDate(const std::string& date) {
	// Check if the date string has the correct format: YYYY-MM-DD
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}
	// Extract year, month, and day from the date string
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	// Check if the extracted values are within valid ranges
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	// Check for valid days in each month
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
	}
	/*Check for valid days in February, considering leap years
	If the year is divisible by 4: It could be a leap year.
	If the year is also divisible by 100: It is not a leap year (century years like 1900 are not leap years).
	If the year is divisible by 400: It is a leap year (e.g., 2000 is a leap year, but 1900 is not).*/ 
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

/*first date that is equal to or later than the provided date*/
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