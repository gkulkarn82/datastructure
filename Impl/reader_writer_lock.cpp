#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

class ReaderWriterLock {
public:
    ReaderWriterLock() : readers(0), writer(false) {}

    // Acquire a read lock
    void lock_read() {
        std::unique_lock<std::mutex> lock(mutex_);
        read_condition.wait(lock, [this]() {
            return !writer; // Wait until there is no writer
        });
        ++readers;
    }

    // Release a read lock
    void unlock_read() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (--readers == 0) {
            write_condition.notify_one(); // Notify writers if there are no readers left
        }
    }

    // Acquire a write lock
    void lock_write() {
        std::unique_lock<std::mutex> lock(mutex_);
        write_condition.wait(lock, [this]() {
            return !writer && readers == 0; // Wait until no writers and no readers
        });
        writer = true;
    }

    // Release a write lock
    void unlock_write() {
        std::lock_guard<std::mutex> lock(mutex_);
        writer = false;
        read_condition.notify_all(); // Notify all waiting readers
        write_condition.notify_one(); // Notify one waiting writer
    }

private:
    std::mutex mutex_;
    std::condition_variable read_condition;
    std::condition_variable write_condition;
    int readers; // Number of current readers
    bool writer; // Flag to indicate if a writer is active
};

// Example usage
void reader_task(ReaderWriterLock& rw_lock, int id) {
    rw_lock.lock_read();
    std::cout << "Reader " << id << " is reading\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate reading
    std::cout << "Reader " << id << " finished reading\n";
    rw_lock.unlock_read();
}

void writer_task(ReaderWriterLock& rw_lock, int id) {
    rw_lock.lock_write();
    std::cout << "Writer " << id << " is writing\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate writing
    std::cout << "Writer " << id << " finished writing\n";
    rw_lock.unlock_write();
}

int main() {
    ReaderWriterLock rw_lock;

    std::thread readers[3];
    std::thread writers[2];

    // Launch reader and writer threads
    for (int i = 0; i < 3; ++i) {
        readers[i] = std::thread(reader_task, std::ref(rw_lock), i + 1);
    }
    for (int i = 0; i < 2; ++i) {
        writers[i] = std::thread(writer_task, std::ref(rw_lock), i + 1);
    }

    // Join all threads
    for (int i = 0; i < 3; ++i) {
        readers[i].join();
    }
    for (int i = 0; i < 2; ++i) {
        writers[i].join();
    }

    return 0;
}
