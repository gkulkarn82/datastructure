/*
    This is the implementation of fixed size(static) Memory Pool.
    I came across one authors design of custom malloc which is impresive
    adding reference here

    Reference :https://github.com/miguelperes/custom-malloc/blob/master/mymemory.c
    This custom malloc is complicated and i am working on it to understand to develop
    the skill of how it is handled
    It handled multiple memory scenario like
    malloc
    free
    custom malloc 
    memory split | chunk split
    merging the chunks
    padding
    increasing memory

    Need to understand this code till that point i will stick to fixed size Memory Pool

*/


#include <iostream>
#include <vector>

class MemoryPool {
public:
    MemoryPool(size_t block_size, size_t num_blocks)
        : block_size_(block_size), num_blocks_(num_blocks) {
        // Allocate a block of memory to serve as the pool
        pool_ = new char[block_size_ * num_blocks_];
        Initialize();
    }

    ~MemoryPool() {
        delete[] pool_;
    }

    // Allocate a block of memory from the pool
    void* Allocate() {
        if (free_list_.empty()) {
            std::cerr << "MemoryPool is exhausted!" << std::endl;
            return nullptr;
        }

        void* ptr = free_list_.back();
        free_list_.pop_back();
        return ptr;
    }

    // Deallocate a block of memory back to the pool
    void Deallocate(void* ptr) {
        if (ptr >= pool_ && ptr < pool_ + (block_size_ * num_blocks_)) {
            free_list_.push_back(ptr);
        }
    }

private:
    size_t block_size_;
    size_t num_blocks_;
    char* pool_;
    std::vector<void*> free_list_;

    // Initialize the memory pool by creating the free list
    void Initialize() {
        for (size_t i = 0; i < num_blocks_; ++i) {
            char* block_ptr = pool_ + (i * block_size_);
            free_list_.push_back(static_cast<void*>(block_ptr));
        }
    }
};

int main() {
    // Create a memory pool with block size 64 bytes and 10 blocks
    MemoryPool pool(64, 10);

    // Allocate and deallocate memory from the pool
    void* ptr1 = pool.Allocate();
    void* ptr2 = pool.Allocate();

    // Use the allocated memory blocks

    pool.Deallocate(ptr1);
    pool.Deallocate(ptr2);

    return 0;
}
