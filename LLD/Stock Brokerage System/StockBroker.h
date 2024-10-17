#include "CommonInclude.h"
#include "Account.h"
#include "Stocks.h"
#include <queue>
#include "Order.h"
#include <random>
#include "StockException.h"

class StockBroker
{
    public:
        static StockBroker* getInstance()
        {
            if(_instance == nullptr)
            {
                lock_guard<mutex> lock(_mu);
                if(_instance == nullptr)
                {
                    _instance = new StockBroker();
                }
            }
            return _instance;
        }    

        void createAccount(User user, double intialBalance)
        {
            string accountId = "11"; //distr(gen);
            Account* acc = new Account(accountId, user, intialBalance);
            _account[accountId] = acc;
        }

        Account* getAccount(string accountId)
        {
            return _account[accountId];
        }

        void addStock(Stocks* stock)
        {
            _stock[stock->getSymbol()] = stock;
        }

        Stocks* getStock(string symbol)
        {
            return _stock[symbol];
        }

        /*
            This should also be thread safe and multi processing
            1. if multiple people are putting orders single queue will not work
            2. how to design a multi queue place order
            3. how to make it more performant
        
        */
        void placeOrder(Order* order)
        {
            _orderQueue.push(order);
            processOrders();
        }


        /*
            This should work as producer and consumer model
            1. Here we should allow multiple users to process orders with thread safety

            possible solution is thread pool of std::function
        */
        void processOrders()
        {
            while(!_orderQueue.empty())
            {
                Order* order = _orderQueue.front();
                _orderQueue.pop();
                try
                {
                    order->execute();
                }
                catch(const InsufficientFundsException& e)
                {
                    std::cerr << e.what() << '\n';
                }
                catch(const InsufficientStockException& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }



    private:        
        static StockBroker* _instance;
        std::mutex _mu;
        std::unordered_map<string , Account*> _account;
        std::unordered_map<string, Stocks*> _stock;
        queue<Order*> _orderQueue;
        std::random_device rd;                  // Get a random number from hardware
        std::mt19937 gen(rd());                 // Seed the generator
        std::uniform_int_distribution<> distr(1, 10000000000);

        StockBroker() = default;
        StockBroker(const StockBroker& obj) = delete;
        StockBroker& operator=(const StockBroker& source) = delete;
        StockBroker(StockBroker&& obj) = delete;
        StockBroker& operator=(const StockBroker&& source) = delete;
        ~StockBroker() = default;
};

StockBroker* StockBroker::_instance = nullptr;
mutex StockBroker::_mu;


