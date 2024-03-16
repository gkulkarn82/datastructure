/*
Variable Template
C++14 allows variables to be templated:

template<class T>
constexpr T pi = T(3.1415926535897932385);
template<class T>
constexpr T e  = T(2.7182818284590452353);

*/

#include<iostream>
#include<complex>
using namespace std;

template<typename T>
//here constexpr is not needed as template it self gets evaluated at compile time
constexpr T pi = T(3.141243131321311L);

int main()
{
    cout.precision(std::numeric_limits<long double>::max_digits10);
    cout << pi<int> << endl;
    cout << pi<float> << endl;
    cout << pi<double> << endl;
    cout << pi<long double> << endl;
    
    cin.get();
    return 0;
}