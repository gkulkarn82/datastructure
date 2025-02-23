#include "TaskQueue.cpp"
#include "ThreadPool.cpp"

class TaskScheduler {
private:
    TaskQueue taskQueue;
    ThreadPool threadPool;

public:
    TaskScheduler(size_t numThreads) 
        : threadPool(numThreads, taskQueue) {}

    // Schedule a new task at a specific time
    void scheduleTask(TaskPtr task) {
        taskQueue.push(std::move(task));
    }

    // Stop the scheduler and ensure all tasks are executed
    void stop() {
        threadPool.stop();
    }
};

int main() {
    TaskScheduler scheduler(4);  // Scheduler with 4 worker threads

    // Schedule tasks with specific execution times
    auto now = steady_clock::now();
    auto time1 = now + seconds(2);  // Task 1 will execute in 2 seconds
    auto time2 = now + seconds(5);  // Task 2 will execute in 5 seconds

    // Create and schedule tasks
    scheduler.scheduleTask(std::make_unique<PrintTask>("Task 1", time1));
    scheduler.scheduleTask(std::make_unique<PrintTask>("Task 2", time2));

    // Allow time for tasks to execute
    std::this_thread::sleep_for(seconds(6));  // Wait long enough for tasks to run

    // Stop the scheduler
    scheduler.stop();

    return 0;
}

