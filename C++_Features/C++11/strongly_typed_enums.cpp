/*
Strongly-typed enums
Type-safe enums that solve a variety of problems with C-style enums including: implicit conversions, inability to specify the underlying type, scope pollution.

// Specifying underlying type as `unsigned int`
enum class Color : unsigned int { Red = 0xff0000, Green = 0xff00, Blue = 0xff };
// `Red`/`Green` in `Alert` don't conflict with `Color`
enum class Alert : bool { Red, Green };
Color c = Color::Red;

*/

#include<iostream>
using namespace std;

/*
    In older style enums 
    when you declare some value in enum like enum Foo {ONE, TWO, THREE};
    => it is consider as global declaration you can not declare any variable with the same name
        e.g int ONE will lead to redeclaration error
        with new enum class it works as it differentiates the scope at class level and global variable

    => same names are not allowed in two differnt enum
        e.g enum foo {ONE, TWO, THREE}
            enum bar {TWO, THREE, FOUR}
        it will raise error if re-declaration for TWO and THREE even if the enums are differnt 

    => in new strongly typed enums enum values are not inter-changable with int
        enum foo {ONE, TWO, THREE} are internally enum foo {ONE = 0, TWO = 1, THREE = 2}
        hence if there is a function
        void fun(int c)
        {
            switch(c)
            {
                case ONE : << "ONE" << endl;
                case TWO : << "ONE" << endl;
            }
        }

        int main()
        {
            fun(ONE); // this was allowed in older way and not allowed in new enum class type
            fun(TWO);
        }

        In new way it has to be like
        void fun(Foo c)
        {
            switch(c)
            {
                case ONE : << "ONE" << endl;
                case TWO : << "ONE" << endl;
            }
        }

        int main()
        {
            fun(Foo::ONE); // this was allowed in older way and not allowed in new enum class type
            fun(Foo::TWO);
        }

    => one more thing was possible which used to create confusion
        enum color {Red, Green , Blue};
        enum people{good , bad};

        int main()
        {
            if(red == good) // this use to work as both of them are on same position zero
                cout << "Red and good are equal";

            // this was a wrong comparision and cannot be done in enum class
        }

*/

// enum Foo {ONE, TWO, THREE};
// enum Bar {ONE , FOUR};

// with adding class before them below error is solved with strong type checking
enum class Foo1 {ONE, TWO, THREE};
enum class Bar1 {ONE , FOUR};

// with new enum classes we can specify which integral type it should support
// like it was int by default starting with 0 index
// this way of speficying integral type can save memory
enum class Foo2: char {ONE, TWO, THREE};
enum class Bar2: short {ONE , FOUR};

int main()
{
    //Foo f = ONE;//error: ‘ONE’ conflicts with a previous declaration
    // is present in both the enums

   // Foo1 = Bar1::ONE; // this is not allowed as they are treated differnt and unique
    //error: expected unqualified-id before ‘=’ token

    // if(Foo1::ONE == Bar1::ONE) // this will fail to fix it we need to cast it
    //     cout << "Hi";

    if(static_cast<int>(Foo1::ONE) == static_cast<int>(Bar1::ONE))
        cout << "Hi" << endl;

    cin.get();
    return 0;
}

