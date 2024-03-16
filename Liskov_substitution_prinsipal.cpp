/*
Liskov Substitution Principal

Def : If class B is subtype of class A then we should be able to repalce object of class of A with B
without breaking behaviour of the program

subclass should extend the capacility of parent class not narrow it down.
*/

#include<bits/stdc++.h>
using namespace std;

class Bike
{
    public:
    vitual void turnOnEngine() = 0;
    virtual void accelerate() = 0;
};

class Motorcycle : Bike
{
    bool isEngineOn;
    int speed;

    public void turnOnEngine() override
    {
        isEngineOn = true;
    }

    public void accelerate() override
    {
        speed = speed + 120;
    }
};

/*
    Here this class is supressing or narrowing the functionality of Bike class
    hence this class is not follwoing the Liskov principal
*/
class Bicycle : Bike
{
     public void turnOnEngine() override
    {
       throw("there is no engine");
    }

    public void accelerate() override
    {
        speed = speed + 10;
    }
}