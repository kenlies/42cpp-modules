#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

using std::cout;
using std::endl;

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initialDeposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initialDeposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initialDeposit;
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		 << "amount:" << this->_amount << ";"
		 << "created" << endl;
}

Account::~Account()
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		 << "amount:" << this->_amount << ";"
		 << "closed" << endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm* timeInfo = std::localtime(&currentTime);
	cout << "[" << std::put_time(timeInfo, "%Y%m%d_%H%M%S") << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts << ";"
		 << "total:" << _totalAmount << ";"
		 << "deposits:" << _totalNbDeposits << ";"
		 << "withdrawals:" << _totalNbWithdrawals << ";" << endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	cout << "index:" << this->_accountIndex << ";"
		 << "p_amount:" << this->_amount - deposit << ";"
		 << "deposit:" << deposit << ";"
		 << "amount:" << this->_amount << ";"
		 << "nb_deposits:" << this->_nbDeposits << endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;
		cout << "index:" << this->_accountIndex << ";"
			 << "p_amount:" << this->_amount + withdrawal << ";"
			 << "withdrawal:" << withdrawal << ";"
			 << "amount:" << this->_amount << ";"
			 << "nb_withdrawals:" << this->_nbWithdrawals << endl;
		return true;
	}
	else
	{
		cout << "index:" << this->_accountIndex << ";"
			 << "p_amount:" << this->_amount << ";"
			 << "withdrawal:refused" << endl;
		return false;
	}
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		 << "amount:" << this->_amount << ";"
		 << "deposits:" << this->_nbDeposits << ";"
		 << "withdrawals:" << this->_nbWithdrawals << endl;
}

int		Account::checkAmount(void) const
{
	return (_amount);
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