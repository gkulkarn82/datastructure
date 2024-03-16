#include <iostream>
#include <chrono>
#include <thread>

class RateLimiter {
public:
    RateLimiter(int maxRequests, std::chrono::milliseconds interval)
        : maxRequests(maxRequests), interval(interval), lastRequestTime(std::chrono::steady_clock::now()) {}

    bool allowRequest() {
        std::lock_guard<std::mutex> lock(mutex);

        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastRequestTime);

        if (elapsedTime < interval && requestCount >= maxRequests) {
            return false; // Rate limit exceeded
        }

        if (elapsedTime >= interval) {
            // Reset the rate limiter for a new interval
            requestCount = 0;
            lastRequestTime = currentTime;
        }

        ++requestCount;
        return true;
    }

private:
    int maxRequests;
    std::chrono::milliseconds interval;
    std::chrono::steady_clock::time_point lastRequestTime;
    int requestCount = 0;
    std::mutex mutex;
};

int main() {
    RateLimiter rateLimiter(5, std::chrono::seconds(1)); // Allow up to 5 requests per second

    for (int i = 0; i < 10; ++i) {
        if (rateLimiter.allowRequest()) {
            std::cout << "Request " << i + 1 << " allowed." << std::endl;
        } else {
            std::cout << "Request " << i + 1 << " blocked due to rate limit." << std::endl;
        }

        // Simulate some processing time between requests
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
