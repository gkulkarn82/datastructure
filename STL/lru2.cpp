#include<bits/stdc++.h>
using namespace std;


class LRUCache
{
public:
    list<int> cache;
    unordered_map<int, list<int>::iterator> umap;
    int cache_size;

    LRUCache(int capacity)
    {
        cache_size = capacity;
    }

    int refer(int key)
    {
        // The key is not present
        if(umap.begin(key) == umap.end())
            return -1;
        else
        {
            // since it is refered now then we need to change it's position to 
            // begin hence erase it's existing entry where eve it is
            umap.erase(key);
        }

        if(cache.size() == cache_size)
        {
            int x = cache.back();
            cache.pop_back();
            umap.erase(x);
        }

        cache.push_front(key);
        umap[key] = cache.begin();
    }
}