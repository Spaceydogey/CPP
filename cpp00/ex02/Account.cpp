/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:26:03 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/16 22:34:06 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit),
										_accountIndex(Account::_nbAccounts),
										_nbDeposits(0), _nbWithdrawals(0)
{
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts += 1;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::~Account()
{
	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";" << "deleted" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "account:" << Account::getNbAccounts() << ";"
				<< "total:" << Account::getTotalAmount() << ";"
				<< "deposit:" << Account::getNbDeposits() << ";"
				<< "withdrawals:" << Account::getNbWithdrawals()
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:"
				<< this->_amount << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "deposit:" << deposit << ";amount:" << this->_amount << ";"
				<< "nb_deposit:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:"
					<< this->_amount << ";withdrawal:";
	if (withdrawal <= this->_amount)
	{
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << this->_amount << ";"
					<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" <<std::endl;
		return (false);
	}	
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::_displayTimestamp(void)
{
		std::time_t now = time(0);
		tm	*ltm = localtime(&now);
		std::cout << "["<< 1900 + ltm->tm_year << 1 + ltm->tm_mon
					<< ltm->tm_mday << "_" << ltm->tm_hour
					<< ltm->tm_min << ltm->tm_sec << "] ";
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:"
				<< this->_amount << ";" << "deposit:" << this->_nbDeposits
				<< ";" << "withdrawals:" << this->_nbWithdrawals << std::endl;
}