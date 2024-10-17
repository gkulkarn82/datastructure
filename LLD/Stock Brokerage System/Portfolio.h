#include "CommonInclude.h"
#include "Account.h"
#include "Stocks.h"
#include "StockException.h"

class Portfolio
{
    public:
        Portfolio(Account* account)
        {
            this->_account = account;
        }

        void addStock(Stocks* stock, size_t quantity)
        {
            _holdings[stock->getSymbol()] += quantity;
        }

        void removeStocks(Stocks* stock, size_t quantity)
        {
            std::lock_guard<std::mutex> lock(_mu);
            string symbol = stock->getSymbol();
            if(_holdings.find(symbol) != _holdings.end())
            {
                size_t currentQuantity = _holdings[symbol];
                if(currentQuantity > quantity)
                {
                    _holdings[symbol] = currentQuantity - quantity;
                }
                else if(currentQuantity == quantity)
                {
                    _holdings.erase(symbol);
                }
                else
                {
                    throw new InsufficientStockException("Insufficient stock quantity in portfolio");
                }
            }
            else
                throw new InsufficientStockException("Stock not found in the protfolio");
        }

        unordered_map<string, int> getHoldings()
        {
            return _holdings;
        }


    private:
        Account* _account;
        unordered_map<string, int> _holdings;
        std::mutex _mu;

};