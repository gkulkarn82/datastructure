#include <thread>
#include <iostream>
#include "ICache.cpp"
#include "CacheManager.cpp"

void cacheTest(ICache& cache) {
    // Writing to the cache
    cache.put("key1", "value1");
    cache.put("key2", "value2");

    // Reading from the cache
    std::cout << "key1: " << cache.get("key1") << std::endl;
    std::cout << "key2: " << cache.get("key2") << std::endl;

    // Removing a key
    cache.remove("key1");
    std::cout << "key1 after removal: " << cache.get("key1") << std::endl;
}

int main() {
    // Initialize CacheManager with 4 shards
    CacheManager cacheManager(4);

    // Simulate concurrent access
    std::thread t1(cacheTest, std::ref(cacheManager));
    std::thread t2(cacheTest, std::ref(cacheManager));

    t1.join();
    t2.join();

    return 0;
}
