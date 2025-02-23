#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class ThreadPool {
public:
    ThreadPool(size_t threads) : stopFlag(false) {
        for (size_t i = 0; i < threads; ++i) {
            workers.emplace_back(&ThreadPool::worker, this);
        }
    }

    ~ThreadPool() {
        stopFlag = true;
        cv.notify_all();
        for (std::thread &worker : workers) {
            worker.join();
        }
    }

    // Add a task to the task queue
    void enqueueTask(std::function<void()> task) {
        std::lock_guard<std::mutex> lock(queueMutex);
        tasks.push(task);
        cv.notify_one();
    }

private:
    void worker() {
        while (!stopFlag) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(queueMutex);
                cv.wait(lock, [this]() { return !tasks.empty() || stopFlag; });
                if (stopFlag) break;
                task = tasks.front();
                tasks.pop();
            }
            task();
        }
    }

    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable cv;
    std::atomic<bool> stopFlag;
};

// Server class
class Server {
public:
    Server(const std::string &host, int port) : threadPool(4) {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket < 0) {
            perror("Failed to create socket");
            exit(1);
        }

        sockaddr_in serverAddr {};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = inet_addr(host.c_str());
        serverAddr.sin_port = htons(port);

        if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            perror("Bind failed");
            exit(1);
        }

        listen(serverSocket, 5);
    }

    void start() {
        while (true) {
            int clientSocket = accept(serverSocket, nullptr, nullptr);
            if (clientSocket < 0) {
                perror("Failed to accept connection");
                continue;
            }

            // Enqueue client handler task
            threadPool.enqueueTask([clientSocket]() {
                handleClient(clientSocket);
            });
        }
    }

private:
    void handleClient(int clientSocket) {
        char buffer[1024];
        while (true) {
            ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesRead <= 0) {
                close(clientSocket);
                return;
            }
            std::string response = "Server: " + std::string(buffer, bytesRead);
            send(clientSocket, response.c_str(), response.size(), 0);
        }
    }

    int serverSocket;
    ThreadPool threadPool;
};

int main() {
    Server server("127.0.0.1", 8080);
    server.start();
    return 0;
}
