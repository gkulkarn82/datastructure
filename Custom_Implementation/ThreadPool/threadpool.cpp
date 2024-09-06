// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>



class ThreadPool
{
public:
    ThreadPool(unsigned int threadsCount = std::thread::hardware_concurrency())
    {
        for (int i = 0; i < threadsCount; ++i)
        {
            _pool.emplace_back([this]
                {
                    while (true)
                    {
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lock(_mutex);
                            _condVar.wait(lock, [this] { return _stop || !_taskQueue.empty(); });

                            if (_stop == true && _taskQueue.empty())
                            {
                                return;
                            }

                            task = _taskQueue.front();
                            _taskQueue.pop();
                        }
                        task();
                    }
                }
            );
        }
        
    }

    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _stop = true;
        }
        _condVar.notify_all();

        for (auto& thd : _pool)
        {
            thd.join();
        }
    }

    void Enqueue(std::function<void()> task)
    {
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _taskQueue.emplace(task);
        }
        _condVar.notify_one();
    }
private:
    std::vector<std::thread> _pool;
    std::queue<std::function<void()>> _taskQueue;
    std::mutex _mutex;
    std::condition_variable _condVar;
    bool _stop = false;
};

int main()
{
    ThreadPool thdPool;

    for (int i = 0; i < 10; ++i)
    {
        thdPool.Enqueue([]
            {
                std::cout << "Task is on" << " Thread id: " << std::this_thread::get_id() << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        );
    }
    return 0;
}