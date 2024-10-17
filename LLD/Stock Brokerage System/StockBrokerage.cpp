#include "CommonInclude.h"
#include "Stocks.h"
#include "Account.h"
#include "Order.h"
#include "BuyOrder.h"
#include "SellOrder.h"
#include "StockBroker.h"

class StockBrokerage
{

}

int main()
{
    StockBroker* broker = StockBroker::getInstance();

    User* user = new User("U001", "John Doe", "john@example.com");
    broker->createAccount(user, 100000.0);

    Account* account = broker->getAccount("A001");
    Stocks* st1 = new Stocks("AAPL", "Apple Inc.", 150.0);
    Stocks* st2 = new Stocks("GOOGL", "Alphabet Inc.", 2000.0);

    boker->addStock(st1);
    boker->addStock(st2);

    Order* buyOrder1 = new BuyOrder("O001", account, stock1, 10, 150.0);
    Order* buyOrder2 = new BuyOrder("O002", account, stock2, 5, 2000.0);
    broker->placeOrder(buyOrder1);
    broker->placeOrder(buyOrder2);

    // Place sell orders
    Order* sellOrder1 = new SellOrder("O003", account, stock1, 5, 160.0);
    broker->placeOrder(sellOrder1);
    broker->removeStock(sellOrder1);

}