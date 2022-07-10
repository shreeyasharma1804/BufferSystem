#include <iostream>
#include<unordered_map>
#include <vector>
#include<list>

using namespace std;

class LRU{

    int capacity = 10;
    unordered_map<int, list<int>::iterator> iterators;
    unordered_map<int, int> values;
    list<int> lru;

    public:

    LRU(){
        cout << "Caching Initialized" << endl;
    }

    void update(int key){
        if(values.find(key) != values.end()){
            lru.erase(iterators[key]);
        }
        lru.push_front(key);
        iterators[key] = lru.begin();
    }

    void remove(){
        iterators.erase(lru.back());
        values.erase(lru.back  ());
        lru.pop_back();
    }

    int get(int key){
        if(values.find(key) == values.end()){
            return -1;
        }
        update(key);
        return values[key];
    }

    void put(int key, int value){
        if(values.size() == capacity and values.find(key) == values.end()){
            remove();
        }
        update(key);
        values[key] = value;
    }



};