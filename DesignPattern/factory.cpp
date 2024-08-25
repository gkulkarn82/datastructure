/*
Factory method is a creational design pattern which solves the problem of creating product objects without specifying their 
concrete classes.

The Factory Method defines a method, which should be used for creating objects instead of using a direct constructor call 
(new operator). Subclasses can override this method to change the class of objects that will be created.

*/

#include<bits/stdc++.h>
using namespace std;

class Product
{
    public:
        virtual ~Product() {};
        virtual std::string Operation() const = 0;
};

class ConcreateProduct1: public Product
{
    public:
        std::string Operation() const override
        {
            return "{Result of the concreate product 1}";
        }
};

class ConcreateProduct2: public Product
{
    public:
        std::string Operation() const override
        {
            return "{Result of the concreate product 2}";
        }
};

class Creator
{
    public:
        virtual ~Creator(){};
        virtual Product* FacotryMethod() const = 0;

        std::string SomeOperation() const 
        {
            // Call the factory method to create a Product object.
            Product* product = this->FacotryMethod();
            // Now, use the product.
            std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
            delete product;
            return result;
        }
};

class ConcreateCreator1 : public Creator
{
    public:
        Product* FacotryMethod() const override
        {
            return new ConcreateProduct1();
        }        
};


class ConcreateCreator2 : public Creator
{
    public:
        Product* FacotryMethod() const override
        {
            return new ConcreateProduct2();
        }        
};

/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator& creator) 
{
  // ...
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator.SomeOperation() << std::endl;
  // ...
}


int main() {
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  
  Creator* creator =  new ConcreateCreator1();
  ClientCode(*creator);
  
  std::cout << std::endl;
  std::cout << "App: Launched with the ConcreteCreator2.\n";
  
  Creator* creator2 = new ConcreateCreator2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;
  return 0;
}