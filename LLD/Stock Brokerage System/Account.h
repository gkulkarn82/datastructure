#include "CommonInclude.h"
#include "User.h"
#include "Portfolio.h"
#include "StockException.h"

class Account
{
public:
    Account() = default;
    Account(std::string accountid, User user, double balance):
            _accountId(accountid), _user(user), _balance(balance)
    {
        this->_portfolio = new Portfolio(this);
    }

    void deposite(double amount)
    {
        std::lock_guard<std::mutex> lock(_mu);
        _balance += amount;
    }

    void withdraw(double amount)
    {
        std::lock_guard<std::mutex> lock(_mu);
        if(_balance >= amount)        
            _balance -= amount;
        else
            throw new InsufficientFundException("Insificient exception in your account");
    }

    string getAccountId()
    {
        return _accountId;
    }

    User* getUser()
    {
        return _user;
    }

    double getBalance()
    {
        return _balance;
    }

    Portfolio* getPortfolio()
    {
        return _portfolio;
    }

private:
    std::string _accountId;
    User* _user;
    double _balance;
    Portfolio* _portfolio; 
    std::mutex _mu;

};