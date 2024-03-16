#include<bits/stdc++.h>
using namespace std;


class LRUCache {    
public:

    int size;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int, int>>::iterator> umap;
    
    LRUCache(int capacity) {
        size = capacity; 
    }
    
    int get(int key) {      
        if(umap.find(key) == umap.end())
            return -1;

        //if key exists please add umap[key] to the beginging of the cache 
        // as part of splice and return the value which is stored in second
        cache.splice(cache.begin(), cache, umap[key]);
        return umap[key]->second;
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end())
        {
            // if key found then add the umap[key] to the begining
            // and assigne the value to that key in map
            cache.splice(cache.begin(), cache, umap[key]);
            umap[key]->second = value;
            return;
        }
        if(cache.size() == size)
        {
            // if the cache is full the get the element from back
            // and the remove it from cache and erase it from map
            auto d_key = cache.back().first;
            cache.pop_back();
            umap.erase(d_key);
        }

        //else push element to the front and assign the begining value to 
        //umap key
        cache.push_front({key, value});
        umap[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache lru(4);
    lru.put(1,10);
    lru.put(2,20);
    lru.put(3,30);
    lru.put(4,40);

    for(auto& c: lru.cache)
    {
        cout << "Key = " << c.first<< " value =  " << c.second << endl;
    }

    cout << "Getting value of key 3 = " <<  lru.get(3) << endl;
    lru.put(5,50);
    lru.put(6,60);
    lru.put(7,70);
    cout << "After couple of more inserts " << endl;
    for(auto& c: lru.cache)
    {
        cout << "Key = " << c.first<< " value =  " << c.second << endl;
    }
    lru.put(8,80);
    lru.put(9,90);

    return 0;

}