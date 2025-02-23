#include "ITask.cpp"
#include <mutex>
#include <condition_variable>
using namespace std;

class TaskQueue {
private:
    //std::queue<TaskPtr> queue;
    std::queue<std::unique_ptr<Task>> queue;
    mutable std::mutex mtx;
    std::condition_variable cv;
    
public:
    // Push a task into the queue
    void push(TaskPtr task) {
        lock_guard<std::mutex> lock(mtx);
        queue.push(std::move(task));
        cv.notify_one();  // Notify worker threads
    }

    // Pop the task with the earliest execution time (blocking until one is available)
    TaskPtr pop() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !queue.empty(); });

        TaskPtr task = std::move(queue.front());
        queue.pop();
        return task;
    }

    bool empty() const{
        std::lock_guard<std::mutex> lock(mtx);
        return queue.empty();
    }
};
