/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:39:30 by jmetayer          #+#    #+#             */
/*   Updated: 2026/06/27 17:44:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account:: _totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return(Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}
int Account::getNbDeposits(void)
{
    return(Account::_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
    return(Account::_totalNbWithdrawals);
}

void    Account::_displayTimestamp(void)
{
    time_t      t_ptr;
    struct tm   *t;

    std::time(&t_ptr);
    t = localtime(&t_ptr);
    std::cout << "[" << t->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << t->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_sec <<"]";
}
void Account::displayAccountsInfos(void)
{   
    _displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" <<Account::getNbWithdrawals() << ";" << std::endl;
}
void Account::makeDeposit(int deposit)
{
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    this->_amount -= withdrawal;
    if (Account::checkAmount())
    {
        this->_amount += withdrawal;
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalNbWithdrawals += 1;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount(void) const
{
    if(this->_amount < 0)
        return(1);
    return(0);
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}
