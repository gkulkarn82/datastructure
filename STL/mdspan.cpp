/*
    1. mdspan means a multidiamentional span
    2. all 


*/

#include<iostream>
#include<vector>
#include<mdspan>
#include<print>
using namespace std;

int main()
{
    vector v={1,2,3,4,5,6,7,8,9,10,11,12};

    auto ms2 = std::mdspan(v.data(), 2, 6);
    auto ms3 = std::mdspan(v.data(), 2, 3, 2);

    for(size_t i = 0; i != ms2.extent(0); i++)
        for(size_t j = 0, j != ms2.extent(1); j++)
            ms2[i, j] = i * 1000 + j;


    for(size_t i = 0; i != ms3.extent(0); i++)
    {
        std::println("slice @ i = {}", i);
        for(size_t j = 0, j != ms3.extent(1); j++)
        {   
            for(size_t k = 0, k != ms3.extent(2); k++)
                std::print("{} ", ms3[i, j, k]);
            std::printlm("")
        }
    }

    return 0;
}

