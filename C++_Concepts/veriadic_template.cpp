/*
    Veriadic Template Function

*/
#include<bits/stdc++.h>
using namespace std;

template<class T>
T add(const T& val)
{
    return val;
}

template<class T, class ... Args>
T add(const T& first, Args ... arg)
{
    return first + add(arg...);
}

namespace own
{
    struct functorAdd
    {
        template<class T>
        T operator()(const T& val)
        {
            return val;
        }

        template<class T, class ... Args>
        T operator()(const T& first, Args ... arg)
        {
            return first + (*this)(arg...);
        }
    };

    struct functorAddCpp17
    {  
        template<class ... Args>
        auto operator()(Args ... arg)
        {
            return (arg + ...);//(*this)(arg) += (*this)(arg...);
        }
    };
};

void print()
{
    cout << "End" << endl;
}

template<class T, class ... Args>
void print(const T& val, Args ... arg)
{
    cout << val << endl;
    print(arg...);
}

template<class ... Args>
void printCpp17(Args ... arg)
{
    //(cout << ... << arg );       
    ([](const auto& x){ cout << x << "\n"; }(arg), ...);
}

int main()
{
    own::functorAdd funcAdd;
    cout << "Addition = " << add(10,20,30,40,100,200,500,150) << endl;
    cout << "Addition Using Functor = " << funcAdd(1,2,3,4,5,6,7,8,9,10) << endl;

    print(10,
          10.9,
          'A',
          "Gajanan" 
          );

    own::functorAddCpp17 funcAdd17;
    cout << "Addition Using Functor C++17 = " << funcAdd17(1,2,3,4,5,6,7,8,9,10) << endl;

     printCpp17(10,
          10.9,
          'A',
          "Gajanan" 
          );
    return 0;
}
