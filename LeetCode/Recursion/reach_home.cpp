#include<iostream>
using namespace std;

void reachHome(int src, int dest)
{
    if(src == dest)
    {
        cout << "reached" << endl;
        return;
    }

    return reachHome(src + 1, dest);
}

int main()
{
    int dest = 10;
    int src = 0;
    reachHome(src, dest);
    return 0;
}