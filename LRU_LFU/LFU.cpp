#include "LFU.h"

using namespace LFU;

int LFUCache::get(int key) {
    if (max_size == 0) return -1;
    if (hash_map_key.count(key)) {
        auto cur = hash_map_key[key];
        int count = cur->count, res = cur->value;
        hash_map_count[count + 1].push_front(Node(cur->key, cur->value, cur->count + 1));
        hash_map_key[cur->key] = hash_map_count[count + 1].begin();
        hash_map_count[count].erase(cur);
        max_count = std::max(max_count, count + 1);
        if (hash_map_count[count].size() == 0 && count == min_count) {
            min_count++;
        }
        printf("Successfully found the key, value is %d \n", res);
        return res;
    }
    else {
        printf("Not found the key %d \n", key);
        return -1;
    }
}

void LFUCache::put(int key, int value) {
    if (max_size == 0) return ;
    if (hash_map_key.count(key)) {
        auto cur = hash_map_key[key];
        int count = cur->count;
        hash_map_count[count + 1].push_front(Node(cur->key, value, cur->count + 1));
        hash_map_key[cur->key] = hash_map_count[count + 1].begin();
        hash_map_count[count].erase(cur);
        max_count = std::max(max_count, count + 1);
        if (hash_map_count[count].size() == 0 && count == min_count) {
            min_count++;
        }
        printf("Successfully put (%d, %d), update \n", key, value);
    }
    else {
        if (hash_map_key.size() == max_size) {
            auto old_node = --hash_map_count[min_count].end();
            int old_key = old_node->key;
            hash_map_key.erase(old_node->key);
            hash_map_count[min_count].pop_back();
            hash_map_count[1].push_front(Node(key, value, 1));
            min_count = 1;
            hash_map_key[key] = hash_map_count[1].begin();
            printf("Successfully put (%d, %d), replace the key %d \n", key, value, old_key);
        }
        else {
            hash_map_count[1].push_front(Node(key, value, 1));
            min_count = 1;
            hash_map_key[key] = hash_map_count[1].begin();
            printf("Successfully put (%d, %d), insert \n", key, value);
        }
    }
}

void LFUCache::display()
{
    for (int i = min_count; i <= max_count; i++) {
        auto dlist = hash_map_count[i];
        if (dlist.size() == 0) continue;
        printf("count %d:", i);
        for (auto node : dlist) {
            printf(" (%d, %d)", node.key, node.count);
        }
        printf("\n");
    }
    
}