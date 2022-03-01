#include "LRU.h"

void LRUCache::pushFront(Node *cur) {
    auto list_head_next = list_head->next;
    list_head_next->pre = cur;
    list_head->next = cur;
    cur->pre = list_head;
    cur->next = list_head_next;
}

void LRUCache::removeNode(Node *cur) {
    cur->pre->next = cur->next;
    cur->next->pre = cur->pre;
}


int LRUCache::get(int key) {
    if (hash_map.find(key) == hash_map.end()) {
        printf("Not found the key %d \n", key);
        return -1;
    }
    auto cur = hash_map[key];
    int value = cur->value;
    removeNode(cur);
    pushFront(cur);
    printf("Successfully found the key, value is %d \n", value);
    return value;
}

void LRUCache::put(int key, int value) {
    if (hash_map.find(key) == hash_map.end()) {
        Node *cur = new Node(key, value);
        if (hash_map.size() == max_size) {
            auto old_node = list_tail->pre;
            int old_value = old_node->value;
            removeNode(old_node);
            hash_map.erase(old_node->key);
            delete old_node;
            pushFront(cur);
            printf("Successfully put (%d, %d), replace the key %d \n", key, value, old_value);
        }
        else {
            pushFront(cur);
            printf("Successfully put (%d, %d), insert \n", key, value);
        }
        hash_map[key] = cur;
    }
    else {
        auto cur = hash_map[key];
        cur->value = value;
        removeNode(cur);
        pushFront(cur);
        printf("Successfully put (%d, %d), update \n", key, value);
    }
}

void LRUCache::display() {
    Node *cur = list_head->next;
    while (cur != list_tail) {
        printf("(%d, %d)", cur->key, cur->value);
        cur = cur->next;
        if (cur != list_tail) {
            printf(" -> ");
        }
    }
    printf("\n");
}