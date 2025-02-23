#include <iostream>
#include <chrono>
#include <memory>
#include <string>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

using namespace std::chrono;

class Task {
public:
    virtual void execute() = 0; // Executes the task
    virtual ~Task() = default;   // Virtual destructor for polymorphism
    
    // Returns the time when the task should be executed
    virtual steady_clock::time_point getExecutionTime() const = 0;
};

using TaskPtr = std::unique_ptr<Task>; // Define a unique pointer type for Task


class PrintTask : public Task {
private:
    std::string message;
    steady_clock::time_point execTime;  // The time when this task should be executed
    
public:
    // Constructor that takes the message and execution time
    PrintTask(const std::string& msg, steady_clock::time_point time)
        : message(msg), execTime(time) {}

    void execute() override {
        std::cout << message << std::endl;
    }

    steady_clock::time_point getExecutionTime() const override {
        return execTime;
    }
};
