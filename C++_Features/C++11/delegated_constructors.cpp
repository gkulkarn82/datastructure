/*
Delegating constructor
If the name of the class itself appears as class-or-identifier in the member initializer list, 
then the list must consist of that one member initializer only; such a constructor is known as the delegating constructor, 
and the constructor selected by the only member of the initializer list is the target constructor.

In this case, the target constructor is selected by overload resolution and executed first, 
then the control returns to the delegating constructor and its body is executed.

Delegating constructors cannot be recursive.

class Foo
{
public: 
    Foo(char x, int y) {}
    Foo(int y) : Foo('a', y) {} // Foo(int) delegates to Foo(char, int)
};

*/

#include<iostream>
using namespace std;


class Foo
{
    private:
        char x, y, z;
    public:
        /*
            both the constructor has duplicate code and to avoid it
            we can write function like init and init is called from both constructor
        */
        void init()
        {
            x = y = z = '!';
        }

        Foo()
        {
            //first way to declare two constructor and use one based on need to achieve setting custom value
            //x = y = z = '!';

            //second way common function
            //init();

            //Third way delegate constructor
            x = y = z = '!';
        }

        Foo(char z) : Foo()
        {
            //first way
            //x = y = '!';

            //second way
            // init()
            // this->z = z;

            //delegate constructor
            this->z = z;
        }

        friend ostream& operator<<(ostream& o, const Foo& f)
        {
            o << "( " << f.x << ", " << f.y << ", " << f.z << ")";
            return o;
        }
};


int main()
{
    Foo alpha;
    cout << alpha << endl;

    Foo beta('z');
    cout << beta << endl;

    cin.get();
    return 0;
}