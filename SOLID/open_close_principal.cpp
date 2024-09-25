/*
Open Close Principal

Def : Open for extension but closed for modification

*/

#include<iostream>
using namespace std;

class Marker
{

public:
    string name;
    string color;
    int year;
    int price;

    Marker(string name, string color, int year, int price)
    {
        this->name = name;
        this->color = color;
        this->year = year;
        this->price = price;
    }
};



class Invoice
{

private:
    Marker marker;
    int quantity;

public:
    Invoice(Marker marker, int quantity)
    {
        this->marker = marker;
        this->quantity = quantity;
    }

    int calculateTotal()
    {
        int price = ((marker.price) * this->quantity);
    }
};

class InvoicePrinter
{

private:
    Invoice invoice;

public:
    InvoicePrinter() = default;
    InvoicePrinter(Invoice inv):invoice(inv)
    {
        
    }

    void printInvoice()
    {
        return;
    }    
};

/*
    As per the principal of open close this class should be open for extension for not for modification

    suppose we need to introduce a methods to save the invoice to file here we have added new methods saveto file
    Now if i add this method this will lead to test the existing tested functionality for savetoDB

    so here we are not extending we are modifuying the already tested calss which due to this becomes vulnerable for defects

*/
class InvoiceDao
{
    Invoice invoice;

    public InvoiceDao(Invoice invoice)
    {
        this->invoice = invoice;
    }

    public void saveToDB() 
    {

    }

    public void saveToFile()
    {

    }
}

/*
    To solve above problem we need to take following steps
    use interface to declare common method and then use different classes to extend from the interface
*/

class InvoiceDao
{
    public:
        virtual void save(Invoice invoice) = 0 // declare the pure virtual method and class becomes abstract class
};

class DatabaseInvoiceDao : InvoiceDao
{
    public void save(Invoice invoice) override
    {
        //save to db
    }
};

class FileInvoiceDao: InvoiceDao
{
    public void save(Invoice invoice) override
    {
        //save to file
    }
};