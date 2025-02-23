#include <vector>
#include <functional>
#include <stdexcept>
#include <mutex>
#include <memory>
#include "Shard.cpp"
#include "ICache.cpp"

class CacheManager : public ICache {
private:
    std::vector<std::shared_ptr<Shard>> shards;  // List of cache shards
    size_t numShards;  // Number of shards in the cache
    std::mutex cacheMutex;  // Mutex to protect cache operations

    // Hash function to determine the shard based on the key
    size_t getShardIndex(const std::string& key) const {
        return std::hash<std::string>{}(key) % numShards;
    }

public:
    // Constructor: Initializes cache manager with a given number of shards
    CacheManager(size_t numShards = 4) : numShards(numShards) {
        // Initialize each shard
        for (size_t i = 0; i < numShards; ++i) {
            shards.push_back(std::make_shared<Shard>());
        }
    }

    // Insert data into the cache, based on the key's shard
    void put(const std::string& key, const std::string& value) override {
        size_t shardIndex = getShardIndex(key);
        shards[shardIndex]->put(key, value);  // Delegate to the appropriate shard
    }

    // Retrieve data from the cache, based on the key's shard
    std::string get(const std::string& key) override {
        size_t shardIndex = getShardIndex(key);
        return shards[shardIndex]->get(key);  // Delegate to the appropriate shard
    }

    // Remove data from the cache, based on the key's shard
    void remove(const std::string& key) override {
        size_t shardIndex = getShardIndex(key);
        shards[shardIndex]->remove(key);  // Delegate to the appropriate shard
    }

    // Check if a key exists in any shard (useful for testing)
    bool contains(const std::string& key) {
        size_t shardIndex = getShardIndex(key);
        return !shards[shardIndex]->get(key).empty();
    }
};
