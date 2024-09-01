/*
    Bounded blocking Thread Safe Queue
    1. There is a maximum limit for the element
    2. This queue will be used by multiple thread
    3. There will 5 consumer threads and 1 producer.    
*/

#include<bits/stdc++.h>
#include <thread>
using namespace std;

namespace own
{
    template<class T>
    class Queue
    {
        public:
            void push(T t)
            {
                lock_guard<mutex> lock(mu);
                qu.push(t);
                cv.notify_all();
            }

            T pop()
            {
                unique_lock<mutex> lock(mu);
                cv.wait(lock, [this](){ return !qu.empty(); });               
                T element = qu.front();
                qu.pop();
                return element;             
            }

        private:
             std::mutex mu;
             condition_variable cv;
             queue<T> qu;
    };

    Queue<int> qu;    
    struct Producer
    {
        void operator()()
        {   
          for(int i = 0 ; i < 10; i++)       
          {
            qu.push(i); 
            cout << "Produced Element = " << i  << " Thread ID = "<< std::this_thread::get_id()<< endl;
          }
        }
    };
   
    struct Consumer
    {
        void operator()()
        {          
           int t  = qu.pop();
           cout << "Consumed Element = " << t << " Thread ID = "<< std::this_thread::get_id() << endl; 
        }
    };
};

int main()
{    
    own::Producer p1;
    own::Consumer c1;
    thread producer(p1);
    thread consume1(c1);
    thread consume2(c1);
    thread consume3(c1);
    thread consume4(c1);
    thread consume5(c1);

    producer.join();
    consume1.join();
    consume2.join();
    consume3.join();
    consume4.join();
    consume5.join();

    return 0;
}