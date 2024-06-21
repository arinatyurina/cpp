/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:26:36 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/19 14:26:37 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip> // for formatted time output

	int Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t t;
	std::time(&t);
	char timestamp[24];
	std::tm	*tm = std::localtime(&t);
	strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", tm);
	/*trftime formats the time components
	 according to the format string 
	and stores them in the timestamp
	 character array.*/
	std::cout << timestamp;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() \
	<< ";total:" << getTotalAmount() \
	<< ";deposits:" << getNbDeposits() \
	<< ";withdrawals:" << getNbWithdrawals() \
	<< std::endl;
}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
	<< ";amount:" << _amount << ";created" \
	<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
	<< ";amount:" << _amount << ";closed" \
	<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
	<< ";p_amount:" << p_amount \
	<< ";deposit:" << deposit \
	<< ";amount:" << _amount \
	<< ";nb_deposits:" << _nbDeposits \
	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;

	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex \
		<< ";p_amount:" << p_amount \
		<< ";withdrawal:" << withdrawal \
		<< ";amount:" << _amount \
		<< ";nb_withdrawals:" << _nbDeposits \
		<< std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex \
		<< ";p_amount:" << p_amount \
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
	<< ";amount:" << _amount \
	<< ";deposits:" << _nbDeposits \
	<< ";withdrawals:" << _nbWithdrawals \
	<< std::endl;
}