/*
    Interface Segmentation Principal

    Def : Interfaces should be such that client should implement unnecessary functions they do not need

*/


class RestaurentEmployee
{
    public:
    virtual void washDishes() = 0;
    virtual void serverCustomers() = 0;
    virtual void cookFood()= 0
};

/*
    Waiter has to implement all the methods
    but waiter is not suppose to implement washDishes or cookFood which is unncessary for this class
*/
class Waiter : RestaurentEmployee
{

    virtual void washDishes() 
    {

    }
    virtual void serverCustomers() override
    {
        cout << "Serving the customers " << endl;
    }

    virtual void cookFood()
    {

    }
}

/*
    To fix this we need to segment the interface in to different
    like below create two different interface with specific task or work
*/

class IWaiterinterface
{
    public:    
    virtual void serverCustomers() = 0;
    virtual void takeOrders()= 0
};

class IChefInterface
{
    public:    
    virtual void cookFood() = 0;
    virtual void decideMenu()= 0
};

class Waiter : IWaiterinterface
{
    
    virtual void serverCustomers() override
    {
        cout << "Serving the customers " << endl;
    }

    virtual void takeOrders() override
    {

    }
}