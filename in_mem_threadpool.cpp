#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <signal.h>

// Including necessary headers
// ...

constexpr int BUFFER_SIZE = 1024;
constexpr int PORT = 1100;

std::unordered_map<std::string, std::string> umapInMem;
std::mutex mu;  


std::string request_get(const std::string& key) {
    std::lock_guard<std::mutex> lock(mu);
    auto it = umapInMem.find(key);
    if (it != umapInMem.end()) {
        return it->second;
    } else {
        return "key missing or not found";
    }
}


void request_put(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mu);
    umapInMem[key] = value;
}

void handleClient(int clntsoc) {
    char buffer[BUFFER_SIZE] = {0};
    ssize_t bytesRead = recv(clntsoc, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead <= 0) {
        close(clntsoc);
        return;
    }

    buffer[bytesRead] = '\0'; 
    std::string request(buffer);

    std::istringstream iss(request);
    std::string command, key, value;
    iss >> command >> key >> value;

    std::string response;
    if (command == "GET") {
        response = request_get(key);
    } else if (command == "PUT") {
        request_put(key, value);
        response = "Put request processed successfully";
    } else {
        response = "Invalid request";
    }

    send(clntsoc, response.c_str(), response.size(), 0);
    close(clntsoc);
}

class ThreadPool {
public:
    ThreadPool(size_t threads) : stop(false)
     {
        for(size_t i = 0; i<threads; ++i)
            workers.emplace_back(
                [this]
                {
                  while(true) 
                  {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock,
                            [this]{ return this->stop || !this->tasks.empty(); });
                        if(this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }

                    task();
                }
            });
    }

    template<class F, class... Args>
    void enqueue(F&& f, Args&&... args){
        auto task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        /*
        std::forward is a standard library function in C++ that takes an argument by value and returns a reference to that object or value. 
        It allows you to pass a value by reference without taking ownership of it, which can be useful in situations where you want to transfer 
        the data but not the ownership of the object. 
        std::forward is defined in the header in the C++ standard library.
        */

        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            // don't allow enqueueing after stopping the pool
            if(stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");

            tasks.emplace(task);
        }
        condition.notify_one();
    }

   ~ThreadPool() {
       {
           std::unique_lock<std::mutex> lock(queue_mutex);
           stop = true;
       }
       condition.notify_all();
       for(std::thread &worker: workers)
           worker.join();
   }

private:
   // Need to keep track of threads so we can join them
   std:vector<std:thread> workers;
   // The task queue
   std:queue<function<void()>> tasks;

   // Synchronization
   mutex queue_mutex;
   condition_variable condition;
   bool stop;
};

volatile sig_atomic_t runServer = true;

void handleSignal(int signal) { 
	runServer = false; 
}

int main() {

	signal(SIGINT, handleSignal);

	ThreadPool pool(4); // Create a thread pool with 4 threads

	int serverSocket; 
	// Socket setup logic...
	// ...

	std:cout << "Server listening on port " << PORT << "...n";

	while (runServer) { 
		sockaddr_in srvAddr{}; 
		socklen_t clntAddrLen sizeof(srvAddr); 

		int clientSocket accept(serverSocket,reinterpret_cast<sockaddr*>(&srvAddr), &clntAddrLen); 
		if (clientSocket == -1) { 
			std:cerr << "Connection accept failed" << endl; 
			continue; 
		} 

		pool.enqueue(handleClient, clientSocket); 
	}

	close(serverSocket); 

	return 0; 
}



The provided C++ code snippet is for a multi-threaded server application that uses a thread pool to handle client requests. Below is an explanation of the key parts of the code:

Header Inclusions: The necessary header files are included for handling input/output streams, strings, unordered maps (for storing key-value pairs), threading, mutexes (for synchronization), vectors, functional programming utilities, and signal handling.

Global Variables:

BUFFER_SIZE and PORT are constants defining the buffer size for reading from sockets and the port number on which the server will listen.
umapInMem is an unordered map acting as an in-memory key-value store.
mu is a mutex used to protect shared data among threads.
Function Definitions:

Placeholder comments indicate where functions like request_get and request_put should be defined. These functions would handle GET and PUT requests from clients.
handleClient Function:

This function reads data from a client socket into a buffer.
It parses commands received from the client and executes them by calling either request_get or request_put.
It sends back a response to the client and closes the socket.
ThreadPool Class:

This class manages a pool of worker threads that can execute tasks concurrently.
The constructor creates worker threads that wait for tasks to be enqueued.
The enqueue method allows adding new tasks to the task queue.
The destructor sets a flag to stop all threads and joins them before exiting.
Signal Handling:

A global variable runServer is used as a flag to control the server's main loop.
The function handleSignal changes this flag when an interrupt signal (SIGINT) is received, which should gracefully stop the server loop.
main Function:

Sets up signal handling for SIGINT.
Initializes a thread pool with 4 threads.
Server socket setup logic should be here (it's indicated by placeholders).
Enters into a loop where it listens for incoming connections on the specified port (PORT). For each accepted connection, it enqueues the task of handling that client to the thread pool.
Error in Code: There are some typos in your code snippet (std:vector, std:queue, etc.). These should be corrected to use double colons (std::vector, std::queue, etc.).