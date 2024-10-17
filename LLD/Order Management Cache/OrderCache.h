#ifndef ORDER_CACHE_H
#define ORDER_CACHE_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <memory>

#include <iostream>
#include <cstdlib>
#include <new>

// Custom allocator
template <typename T>
class CustomAllocator {
public:
    using value_type = T;

    CustomAllocator() = default;

    template <typename U>
    CustomAllocator(const CustomAllocator<U>&) {}

    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " object(s) of size " << sizeof(T) << std::endl;
        if (n > std::size_t(-1) / sizeof(T)) {
            throw std::bad_alloc();
        }
        if (auto ptr = static_cast<T*>(std::malloc(n * sizeof(T)))) {
            return ptr;
        }
        throw std::bad_alloc();
    }

    void deallocate(T* p, std::size_t) noexcept {
        std::cout << "Deallocating memory" << std::endl;
        std::free(p);
    }
};

// Comparison operators for allocator
template <typename T, typename U>
bool operator==(const CustomAllocator<T>&, const CustomAllocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const CustomAllocator<T>&, const CustomAllocator<U>&) { return false; }

// Class to be managed by unique_ptr
// class MyClass {
// public:
//     MyClass(int value) : value(value) {
//         std::cout << "MyClass constructed with value: " << value << std::endl;
//     }

//     ~MyClass() {
//         std::cout << "MyClass with value " << value << " destructed." << std::endl;
//     }

//     void display() const {
//         std::cout << "Value: " << value << std::endl;
//     }

// private:
//     int value;
// };

// int main() {
//     // Create a vector of unique_ptr with a custom allocator
//     std::vector<std::unique_ptr<MyClass>, CustomAllocator<std::unique_ptr<MyClass>>> myVector;

//     // Inserting unique_ptr into the vector
//     myVector.push_back(std::make_unique<MyClass>(1));
//     myVector.push_back(std::make_unique<MyClass>(2));
//     myVector.push_back(std::make_unique<MyClass>(3));

//     std::cout << "Current elements in vector:" << std::endl;
//     for (const auto& ptr : myVector) {
//         ptr->display();
//     }

//     return 0;
// }


enum class OrderSide {
    Buy,
    Sell
};

class Order {
public:
    std::string orderId;
    std::string securityId;
    OrderSide side;
    int quantity;
    std::string userId;
    std::string companyId;

    Order(const std::string& orderId, const std::string& securityId, OrderSide side,
          int quantity, const std::string& userId, const std::string& companyId)
        : orderId(orderId), securityId(securityId), side(side),
          quantity(quantity), userId(userId), companyId(companyId) {}

    ~Order() = default;
};

class OrderCacheInterface {
public:
    virtual void addOrder(const Order& order) = 0;
    virtual void cancelOrder(const std::string& orderId) = 0;
    virtual void cancelOrdersForUser(const std::string& userId) = 0;
    virtual void cancelOrdersForSecIdWithMinimumQty(const std::string& securityId, int minimumQty) = 0;
    virtual int getMatchingSizeForSecurity(const std::string& securityId) = 0;
    virtual std::vector<Order> getAllOrders() = 0;

    virtual ~OrderCacheInterface() = default;
};

class OrderCache : public OrderCacheInterface {
private:
    std::unordered_map<std::string, Order> orderMap; // Maps orderId to Order
    //std::unordered_map<std::string, std::vector<Order*>> ordersBySecurity; // Maps securityId to orders
    std::unordered_map<std::string, std::vector<std::unique_ptr<Order>>> ordersBySecurity; // Maps securityId to orders
    //std::unordered_map<std::string, std::vector<std::unique_ptr<Order> , CustomAllocator<std::unique_ptr<Order>>>> ordersBySecurity;
    //std::vector<std::unique_ptr<Order>, std::allocator<Order>(CustomAllocator<std::unique_ptr<Order>>)> ordersBySecurity;
    std::unordered_map<std::string, std::unordered_set<std::string>> companyOrders; // Maps companyId to orderIds

   
public:
    void addOrder(const Order& order) override;
    void cancelOrder(const std::string& orderId) override;
    void cancelOrdersForUser(const std::string& userId) override;
    void cancelOrdersForSecIdWithMinimumQty(const std::string& securityId, int minimumQty) override;
    int getMatchingSizeForSecurity(const std::string& securityId) override;
    std::vector<Order> getAllOrders() override;
};

#endif // ORDER_CACHE_H
