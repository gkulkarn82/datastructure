#include <string>
#include <memory>

// Cache interface for thread-safe cache operations
class ICache {
public:
    virtual ~ICache() = default;
    
    // Insert data into cache
    virtual void put(const std::string& key, const std::string& value) = 0;

    // Retrieve data from cache
    virtual std::string get(const std::string& key) = 0;

    // Remove data from cache
    virtual void remove(const std::string& key) = 0;
};
