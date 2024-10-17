#include<iostream>
#include<vector>
#include<string>
#include<mutex>
#include<thread>
#include<condition_variable>
#include <unordered_map>
#include <unordered_set>
#include<cstdlib>
#include<exception>
using namespace std;

enum class OrderStatus
{
    PENDING,
    EXECUTED,
    REJECTED
};