#include<chrono>
#include<iostream>
#include<random>
#include<vector>
#include<mutex>
#include<numeric>
#include<atomic>

constexpr long long size = 100000000;

int main()
{
    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);


    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(1, 10);
    for(long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    const auto sta = std::chrono::steady_clock::now();
     
     
    //Case I
    // unsigned long long sum = {};
    // for (auto n: randValues) sum += n;

    
    //Case II
    //const auto sum = std::accumulate(randValues.begin(), randValues.end(), 0);

    //Case III
    // std::mutex myMutex;
    // unsigned long long sum = {};
    // for (auto i: randValues){
    //     std::lock_guard<std::mutex> myLockGuard(myMutex);
    //     sum += i;
    // }

    //Case IV
    std::atomic<unsigned long long> sum = {};
    std::cout << std::boolalpha << "sum.is_lock_free(): " 
        << sum.is_lock_free() << std::endl;
    std::cout << std::endl;

    //auto sta = std::chrono::steady_clock::now();

    for (auto i: randValues) sum += i;

    const std::chrono::duration<double> dur =  std::chrono::steady_clock::now() - sta;
    std::cout << "Time for mySumition " << dur.count()  << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;


    sum = 0;
    sta = std::chrono::steady_clock::now();

    for (auto i: randValues) sum.fetch_add(i);

    dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addition " << dur.count()  << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;

    std::cout << std::endl;
}