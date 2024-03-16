/*
Adapter is a structural design pattern, which allows incompatible objects to collaborate.

The Adapter acts as a wrapper between two objects.
It catches calls for one object and transforms them to format and interface recognizable by the second object.

*/

#include<bits/stdc++.h>
using namespace std;

class Target
{
    public:
    virtual ~Target() {};
    virtual std::string Request() const
    {
        return "Target: The default target's behaviour";
    }
};

class Adaptee
{
    public:
        std::string SpecificRequest() const
        {
            return ".eetpadA eht fo rovivaheb laicepsS";
        }
};

class Adapter: public Target
{
    private:
        Adaptee *adaptee_;
    public:
        Adapter(Adaptee *adaptee) : adaptee_(adaptee){};
        std::string Request() const override
        {
            std::string to_reverse  = this->adaptee_->SpecificRequest();
            std::reverse(to_reverse.begin(), to_reverse.end());
            return "Adapter: (TRANSLATED) " + to_reverse;
        }
};

void ClientCode(const Target *target)
{
    std::cout << target->Request();
}

int main()
{
    std::cout << "Client: I can work just fine with the Target objects:\n";
    
    Target *target = new Target;
    ClientCode(target);
    
    std::cout << "\n\n";
    
    Adaptee *adaptee = new Adaptee;
    
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
}