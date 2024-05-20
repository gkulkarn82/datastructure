/*

*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

namespace own
{
    template<class T>
    class ITask
    {
        public:
            ITask() = default;
            ~ITask() = default;        
            virtual T operator()(const T& a, const T& b) = 0;
        private:
    };

    template<class T>
    struct Add: public ITask<T>
    {
        T operator()(const T& a,const T& b)
        {
            return a + b;
        }
    };

    template<class T>
    struct Subtract: public ITask<T>
    {
        T operator()(const T& a,const T& b)
        {
            return a - b;
        }
    };
};

int main()
{
    own::Add<int> objadd;
    own::Subtract<int> objsubtract;
    vector<own::ITask<int>*> vTask;
    vTask.push_back(&objadd);
    vTask.push_back(&objsubtract);

    for(auto &out: vTask)
    {
        (*out)(20,10);
    }


    cout<< "Addition = " << objadd(10,20) << endl;
    cout<< "Subtraction = " << objsubtract(20,10) << endl;


    return 0;
}