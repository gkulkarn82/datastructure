/*
Initializer lists
A lightweight array-like container of elements created using a "braced list" syntax. For example, { 1, 2, 3 } creates a sequences of 
integers, that has type std::initializer_list<int>. Useful as a replacement to passing a vector of objects to a function.

int sum(const std::initializer_list<int>& list) {
  int total = 0;
  for (auto& e : list) {
    total += e;
  }

  return total;
}

auto list = {1, 2, 3};
sum(list); // == 6
sum({1, 2, 3}); // == 6
sum({}); // == 0


*/

#include<iostream>
#include<vector>
using namespace std;


struct Foo
{
    int x;
    float f;
};

int main()
{
    int arr[] {8, 6, 7};
    Foo f{3, 1.24};

    vector<int> v{1,2,3,4,5};
    double d {3.14};
    cout << d << endl;

    int i {};
    int a[5] = {};
    cout << a[1] << endl;

    cin.get();
    return 0;
}