#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <mutex>

const size_t CHUNK_SIZE = 1024 * 1024; // 1 MB per chunk
std::mutex print_mutex;

void read_chunk(const std::string& filename, size_t start, size_t end, size_t thread_id) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }

    // Move the file pointer to the start of the chunk
    file.seekg(start);

    // Calculate the size of the chunk
    size_t size = end - start;
    std::vector<char> buffer(size);

    // Read the chunk into the buffer
    file.read(buffer.data(), size);

    // Print chunk information (for demonstration purposes)
    std::lock_guard<std::mutex> guard(print_mutex);
    std::cout << "Thread " << thread_id << " read chunk from " << start << " to " << end << "\n";
    // Optionally, you could process the buffer here

    file.close();
}

int main() {
    const std::string filename = "largefile.bin"; // Replace with your file
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    size_t file_size = file.tellg();
    file.close();

    size_t num_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    // Calculate chunk size and create threads
    for (size_t i = 0; i < num_threads; ++i) {
        size_t start = i * CHUNK_SIZE;
        size_t end = std::min(start + CHUNK_SIZE, file_size);
        threads.emplace_back(read_chunk, filename, start, end, i);
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
