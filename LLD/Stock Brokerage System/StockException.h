#include "CommonInclude.h"

class InsufficientFundsException : public exception
{
    public:
        InsufficientFundsException(string message):_message(message)
        {}

        // Override the what() method to return our message
        const char* what() const throw()
        {
            return _message.c_str();
        }
    private:
        string _message;
};


class InsufficientStockException : public exception
{
    public:
        InsufficientStockException(string message):_message(message)
        {}

        // Override the what() method to return our message
        const char* what() const throw()
        {
            return _message.c_str();
        }
    private:
        string _message;
};