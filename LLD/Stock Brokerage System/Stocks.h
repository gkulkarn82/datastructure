#include<iostream>
#include<string>
#include<mutex>
using namespace std;

std::mutex mu;

class Stocks
{
    public:
        Stocks(string symbol, string name, double price):_symbol(symbol), _name(name), _price(price)
        {}

        void updatePrice(double newPrice)
        {
            std::lock_guard<std::mutex> lock(mu);
            _price = newPrice;
        }

        string getSymbol()
        {
            return _symbol;
        }

        string getName()
        {
            return _name;
        }

        double getPrice()
        {
            return _price;
        }


    private:
        string _symbol;
        string _name;
        double _price;
};