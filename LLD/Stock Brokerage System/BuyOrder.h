#include "CommonInclude.h"
#include "Order.h"
#include "StockException.h"

class BuyOrder : Order
{
    public:
        BuyOrder(string orderId, Account* account, Stocks stock, size_t quntity, double price):
                Order(orderId, account, stock, quntity, price) , _quantity(quntity), _price(price),
                _account(account)
        {

        }

        void execute() override
        {
            double totalCost = _quantity * _price;

            if(_account.getBalance() >= totalCost)
            {
                _account->withdraw(totalCost);
                _status = OrderStatus::EXECUTED;
            }
            else
            {
                _status = OrderStatus::REJECTED;
                throw new InsufficientFundsException("Insufficient Funds to execute the order");
            }
        }
    private:
        size_t _quantity;
        double _price;
        Account* _account;
        OrderStatus _status;
};
