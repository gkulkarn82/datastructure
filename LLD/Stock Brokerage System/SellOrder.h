#include "CommonInclude.h"
#include "Order.h"

class SellOrder : Order
{
    public:
        SellOrder(string orderId, Account account, Stocks stock, size_t quntity, double price):
                Order(orderId, account, stock, quntity, price) , _quantity(quntity), _price(price),
                _account(account)
        {

        }

        void execute() override
        {
            double totalProceeds = _quantity * _price;
            _account->deposite(totalProceeds);
            _status = OrderStatus::EXECUTED;
        }
    private:
        size_t _quantity;
        double _price;
        Account* _account;
        OrderStatus _status;
};
