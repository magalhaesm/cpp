/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:41:08 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/03 10:33:15 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}
Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = _amount;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << _amount  << ";"
			<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";"
			<< "withdrawal:";

	if (checkAmount() && withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;

		std::cout << withdrawal << ";"
			<< "amount:" << _amount << ";"
			<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}

	std::cout << "refused" << std::endl;
	return false;
}

int	Account::checkAmount( void ) const
{
	if ((_totalAmount - _amount) > 0)
		return 1;
	return 0;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "deposits:" << _nbDeposits << ";"
			<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	char		timestamp[100];
	std::time_t	currentTime = std::time(0);

	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]",
			std::localtime(&currentTime));

	std::cout << timestamp << " ";
}
