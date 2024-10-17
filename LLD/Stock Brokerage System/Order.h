#include "CommonInclude.h"
#include "Account.h"
#include "Stocks.h"

class Order
{
    public:
        Order(string orderId, Account account, Stocks stock, size_t quantity, double price):
            _orderId(orderId), _account(account), _stock(stock),_quantity(quantity), _price(price)
        {

        }

        virtual void execute() = 0;
    private:
        string _orderId;
        Account _account;
        Stocks _stock;
        size_t _quantity;
        double _price;
        OrderStatus _status;
};