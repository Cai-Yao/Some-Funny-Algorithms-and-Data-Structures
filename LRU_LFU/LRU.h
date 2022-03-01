#ifndef __LRU_H__
#define __LRU_H__

#include <unordered_map>

class Node
{
public:
    Node *pre = nullptr;
    Node *next = nullptr;
    int key, value;
    Node() {}
    Node(int key, int value) : key(key), value(value) {} 
};

class LRUCache
{
public:
    LRUCache(int capacity) : max_size(capacity) {
        list_head = new Node();
        list_tail = new Node();
        list_head->next = list_tail;
        list_tail->pre = list_head;
    }
    ~LRUCache() {
        Node *cur = list_head;
        while (cur != nullptr) {
            auto tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }
    int get(int key);   
    void put(int key, int value);
    void display();

private:
    Node *list_head;
    Node *list_tail;
    std::unordered_map<int, Node*> hash_map;
    int max_size;
    void pushFront(Node *cur);
    void removeNode(Node *node);

};



#endif