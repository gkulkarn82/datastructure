/*
Single Responsibility Principal

Def : A Class should have only one reason to change

*/

#include <bits/stdc++.h>;
using namespace std;

class Marker
{

public:
    string name;
    string color;
    int year;
    int price;

    public Marker(string name, string color, int year, int price)
    {
        this.name = name;
        this.color = color;
        this.year = year;
        this.price = price;
    }
};


/*
    This class has multiple reason to change
    1. the method to calculate the total can change if i need to bring in change to GST or apply discoount
    2. if there is a change in printing logic then this becomes one more reason to change this class
    3. savetodb is one more reason if i need to introduce method to save it to file then this becomes one more reason


    Due to these reasons this calss can not be concluded to be following single responsible principal
*/

class Invoice
{
    private Marker marker;
    private int quantity;

    public Invoice(Marker marker, int quantity)
    {
        this->marker = marker;
        this->quantity = quantity;
    }

    public int calculateTotal()
    {
        int price = ((marker.price) * this->quantity);
    }

    public void printInvoice()
    {}

    public void saveToDB()
    {}
};


/*
    Solution to above problem is to divided them in different classes with their 
    individual responsibility
*/
class Invoice
{
    private Marker marker;
    private int quantity;

    public Invoice(Marker marker, int quantity)
    {
        this->marker = marker;
        this->quantity = quantity;
    }

    public int calculateTotal()
    {
        int price = ((marker.price) * this->quantity);
    }
};

class InvoicePrinter
{
    Invoice Invoice;

    public InvoicePrinter(Invoice invoice)
    {
        this.invoice = invoice;
    }

    public void printInvoice()
    {

    }    
}

class InvoiceDao
{
    Invoice invoice;

    public InvoiceDao(Invoice invoice)
    {
        this->invoice = invoice;
    }

    public void saveToDB()
}
