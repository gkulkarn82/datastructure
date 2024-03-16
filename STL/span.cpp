/*

    1. span<T, N> is the signature where T is type and N for size
    2. this is lightweight because it do not contains your values.
    3. It can support contiguos memory array or vector
    4. We can use it to iterate over any one of the contiguous array
    5. It can update the data inside the type of contiguous array
*/

#include<iostream>
#include<vector>
#include<array>
#include<span>
using namespace std;

void print_content(std::span<int> container)
{
    for(const auto& e: container)
        cout << e << ' ';
    cout << endl;
}

int main()
{
    int a[]{23,45,67, 89};
    print_content(a);

    std::vector v{1,2,3,4,5};
    print_content(v);

    std::array a2{-14,55,24,67};
    print_content(a2);

    return 0;


}