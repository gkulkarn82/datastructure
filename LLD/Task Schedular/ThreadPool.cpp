#include <atomic>
#include <thread>
#include <vector>
#include <TaskQueue.cpp>

class ThreadPool {
private:
    std::vector<std::thread> workers;
    TaskQueue& taskQueue;   // Reference to the task queue
    std::atomic<bool> stopFlag;  // Flag to stop threads gracefully
    
    void workerThread() {
        while (!stopFlag) {
            TaskPtr task = taskQueue.pop();
            auto now = steady_clock::now();
            auto execTime = task->getExecutionTime();

            if (execTime > now) {
                std::this_thread::sleep_for(execTime - now);  // Sleep until execution time
            }

            task->execute();  // Execute the task
        }
    }

public:
    ThreadPool(size_t numThreads, TaskQueue& queue) 
        : stopFlag(false), taskQueue(queue) {
        // Launch worker threads
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back(&ThreadPool::workerThread, this);
        }
    }

    // Stop all threads
    void stop() {
        stopFlag = true;
        for (auto& worker : workers) {
            if (worker.joinable()) {
                worker.join();  // Join each thread
            }
        }
    }

    ~ThreadPool() {
        if (!stopFlag) {
            stop();  // Ensure threads are stopped if not already
        }
    }
};
