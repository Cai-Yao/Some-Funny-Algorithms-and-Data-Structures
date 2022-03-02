#ifndef __LFU_H__
#define __LFU_H__


#include <unordered_map>
#include <list>

namespace LFU {
class Node {
public:
    int key, value, count;
    Node(int _key, int _value, int _count) : key(_key), value(_value), count(_count) {}
};

class LFUCache {
public:
    LFUCache(int capacity) : max_size(capacity){
        hash_map_key.clear();
        hash_map_count.clear();
    }
    int get(int key);
    void put(int key, int value);
    void display();

private:
    std::unordered_map<int, std::list<Node>::iterator> hash_map_key;
    std::unordered_map<int, std::list<Node>> hash_map_count;
    int max_size, min_count = 0, max_count = 1;
};
}

#endif