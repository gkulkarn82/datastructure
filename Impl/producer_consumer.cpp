//producer consumer

#include<iostream>
#include<thread>
#include<condition_variable>
#include<vector>
#include<queue>
using namespace std;

std::mutex mu;
std::condition_variable cv;
std::queue<int> qu;

void producer()
{
	int item = 0;
    while(true)
    {
        std::lock_guard<std::mutex> lock(mu);
        qu.push(item);
        cout << "Item is produced = " << item << endl;
        ++item;
        cv.notify_one();
    }
}


void consumer()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mu);
        cv.wait(lock, [](){return !qu.empty();});
        int item = qu.front();
        qu.pop();
        cout << "Item is consumed = " << item << endl;
        //cv.notify_one();
    }
}


int main()
{
	std::thread t1(producer);
	std::vector<std::thread> consumer_t;
	
	for(int i = 0 ;i < 4; ++i)
	{
		consumer_t.emplace_back(consumer);
	}

    t1.join();
    for(auto& i : consumer_t)
         i.join();

    return 0;

}