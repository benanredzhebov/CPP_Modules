/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:47:07 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/06 16:13:21 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0; // tracks the total number of accounts.
int	Account::_totalAmount = 0; // tracks the total balance across all accounts.
int	Account::_totalNbDeposits = 0; // tracks the total number of deposits across all accounts.
int	Account::_totalNbWithdrawals = 0; // tracks the total number of withdrawals across all accounts.

Account::Account	(int initial_deposit) : _accountIndex(Account::_nbAccounts),
		_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account (void) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
}

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void	Account::makeDeposit(int deposit) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	_totalAmount += deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {

	_displayTimestamp();
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal;
	_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus (void) const {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos() {

	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:";
	std::cout << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void) {

	time_t t = time(NULL);
	tm *local_time = localtime(&t);
	std::cout << "[" << local_time->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mday;
	std::cout << "_" << std::setw(2) << std::setfill('0') << local_time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_sec << "] ";
}