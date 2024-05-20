#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
 
using namespace std::chrono_literals;
 
struct Base
{
    Base() { std::cout << "Base::Base()\n"; }
 
    // Note: non-virtual destructor is OK here
    ~Base() { std::cout << "Base::~Base()\n"; }
};
 
struct Derived : public Base
{
    Derived() { std::cout << "Derived::Derived()\n"; }
 
    ~Derived() { std::cout << "Derived::~Derived()\n"; }
};
 
void print(auto rem, std::shared_ptr<Base> const& sp)
{
    std::cout << rem << "\n\tget() = " << sp.get()
              << ", use_count() = " << sp.use_count() << '\n';
}
 
void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(987ms);
    std::shared_ptr<Base> lp = p; // thread-safe, even though the
                                  // shared use_count is incremented
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        print("Local pointer in a thread:", lp);
    }
}
 
int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();
 
    print("Created a shared Derived (as a pointer to Base)", p);
 
    std::thread t1{thr, p}, t2{thr, p}, t3{thr, p};
    p.reset(); // release ownership from main
 
    print("Shared ownership between 3 threads and released ownership from main:", p);
 
    t1.join();
    t2.join();
    t3.join();
 
    std::cout << "All threads completed, the last one deleted Derived.\n";
}
Possible output:

Base::Base()
Derived::Derived()
Created a shared Derived (as a pointer to Base)
	get() = 0x118ac30, use_count() = 1
Shared ownership between 3 threads and released ownership from main:
	get() = 0, use_count() = 0
Local pointer in a thread:
	get() = 0x118ac30, use_count() = 5
Local pointer in a thread:
	get() = 0x118ac30, use_count() = 4
Local pointer in a thread:
	get() = 0x118ac30, use_count() = 2
Derived::~Derived()
Base::~Base()
All threads completed, the last one deleted Derived.
Example
Run this code
#include <iostream>
#include <memory>
 
struct MyObj
{
    MyObj() { std::cout << "MyObj constructed\n"; }
 
    ~MyObj() { std::cout << "MyObj destructed\n"; }
};
 
struct Container : std::enable_shared_from_this<Container> // note: public inheritance
{
    std::shared_ptr<MyObj> memberObj;
 
    void CreateMember() { memberObj = std::make_shared<MyObj>(); }
 
    std::shared_ptr<MyObj> GetAsMyObj()
    {
        // Use an alias shared ptr for member
        return std::shared_ptr<MyObj>(shared_from_this(), memberObj.get());
    }
};
 
#define COUT(str) std::cout << '\n' << str << '\n'
 
#define DEMO(...) std::cout << #__VA_ARGS__ << " = " << __VA_ARGS__ << '\n'
 
int main()
{
    COUT("Creating shared container");
    std::shared_ptr<Container> cont = std::make_shared<Container>();
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
 
    COUT("Creating member");
    cont->CreateMember();
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
 
    COUT("Creating another shared container");
    std::shared_ptr<Container> cont2 = cont;
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
    DEMO(cont2.use_count());
    DEMO(cont2->memberObj.use_count());
 
    COUT("GetAsMyObj");
    std::shared_ptr<MyObj> myobj1 = cont->GetAsMyObj();
    DEMO(myobj1.use_count());
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
    DEMO(cont2.use_count());
    DEMO(cont2->memberObj.use_count());
 
    COUT("Copying alias obj");
    std::shared_ptr<MyObj> myobj2 = myobj1;
    DEMO(myobj1.use_count());
    DEMO(myobj2.use_count());
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
    DEMO(cont2.use_count());
    DEMO(cont2->memberObj.use_count());
 
    COUT("Resetting cont2");
    cont2.reset();
    DEMO(myobj1.use_count());
    DEMO(myobj2.use_count());
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
 
    COUT("Resetting myobj2");
    myobj2.reset();
    DEMO(myobj1.use_count());
    DEMO(cont.use_count());
    DEMO(cont->memberObj.use_count());
 
    COUT("Resetting cont");
    cont.reset();
    DEMO(myobj1.use_count());
    DEMO(cont.use_count());
}