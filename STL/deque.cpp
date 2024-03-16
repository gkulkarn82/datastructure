/*
    1. Deque is an index sequence container
    2. it allows fast insetion and deletion at both begining and end
    3. unlike vector elements deque are not stored  contiguous
    4. It uses individual allocated fixed size array with additional bookkeeping . meaning index based access to deque must
    perform two pointer dereference
    5. the storage of deque is automatically expanded or contracted as needed
    6. Expansion of deque is cheaper than vector
    7. A deque holding just one element has to allocate its full internal array
    (e.g 8 times the object size on 64 bit )

*/

#include<iostream>
#include<deque>
using namespace std;

void print(const std::deque<int>& dqu)
{
    for(int num : dqu)
    {
        cout << num << " " << endl;
    }
}

int main()
{
    {
        deque<int> dq = {2,3,4};
        dq.push_front(1);
        dq.push_back(5);
        print(dq);
    }
     {
        deque<int> dq = {2,3,4};
        dq.pop_front();
        dq.pop_back();
        print(dq);
    }
    return 0;
} 