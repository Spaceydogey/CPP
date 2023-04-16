/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:26:03 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/16 16:57:32 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit) : _amount(initial_deposit),
										_accountIndex(_nbAccounts),
										_nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += _amount;
	_nbAccounts += 1;
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::~Account()
{
	_totalAmount -= _amount;
	_nbAccounts -= 1;
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";" << "deleted" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "account:" << Account::getNbAccounts() << ";"
				<< "amount:" << Account::getTotalAmount() << ";"
				<< "deposit:" << Account::getNbDeposits() << ";"
				<< "withdrawals:" << Account::getNbWithdrawals()
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits += 1;
	this->_totalNbDeposits += 1;
	this->_totalNbDeposits += 1; 
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:"
				<< this->_amount << ";";
	this->_amount += deposit;
	std::cout << "deposit:" << deposit << ";amount:" << this->_amount << ";"
				<< "nb_deposit:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	
}