#include <unordered_map>
#include <shared_mutex>
#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

// A single shard of the cache, which is thread-safe
class Shard {
private:
    std::unordered_map<std::string, std::string> data; // Key-value store
    mutable std::shared_mutex mutex;  // Shared mutex for thread-safe access

public:
    // Insert data into the shard
    void put(const std::string& key, const std::string& value) {
        std::unique_lock<std::shared_mutex> lock(mutex);  // Exclusive lock for write
        data[key] = value;
    }

    // Retrieve data from the shard
    std::string get(const std::string& key) {
        std::shared_lock<std::shared_mutex> lock(mutex);  // Shared lock for read
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        return "";  // Return empty string if key is not found
    }

    // Remove data from the shard
    void remove(const std::string& key) {
        std::unique_lock<std::shared_mutex> lock(mutex);  // Exclusive lock for write
        data.erase(key);
    }
};
