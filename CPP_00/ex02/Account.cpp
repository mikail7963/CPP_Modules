#include <iostream>
#include "Account.hpp"
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    std::tm* local_time = std::localtime(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local_time);
    std::cout << buffer;
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout <<  "index:" <<  this->_accountIndex << ";amount:" << checkAmount() << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
    int p_amount = checkAmount();
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount 
              << ";deposit:" << deposit 
              << ";amount:" << checkAmount()
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:";
    if (checkAmount() < withdrawal)
    {
        std::cout  << "refused" << std::endl;
        return false;
    }
    this->_nbWithdrawals++;
    this->_amount -= withdrawal;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}


void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout   << "accounts:" << getNbAccounts() 
                << ";total:" << getTotalAmount() 
                << ";deposits:" << getNbDeposits()
                << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
    _displayTimestamp();
    std::cout << "index:" << getNbAccounts() << ";amount:" << initial_deposit <<  ";created" << std::endl;
    this->_accountIndex = getNbAccounts();
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout <<  "index:" << this->_accountIndex << ";amount:"  << checkAmount() <<  ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
    return _amount;
}
