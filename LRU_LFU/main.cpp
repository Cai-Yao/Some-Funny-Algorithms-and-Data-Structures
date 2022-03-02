#include "LRU.h"
#include "LFU.h"

int main()
{
    printf("-------------------LRU---------------------\n");
    LRU::LRUCache lru_cache(2);
    lru_cache.put(1, 1);
    lru_cache.put(2, 2);
    lru_cache.get(1);
    lru_cache.put(3, 3);
    lru_cache.get(2);
    lru_cache.put(4, 4);
    lru_cache.get(1);
    lru_cache.get(3);
    lru_cache.get(4);
    lru_cache.display();
    printf("\n-------------------LFU---------------------\n");
    LFU::LFUCache lfu_cache(2);
    lfu_cache.put(1, 1);
    lfu_cache.put(2, 2);
    lfu_cache.get(1);
    lfu_cache.put(3, 3);
    lfu_cache.get(2);
    lfu_cache.get(3);
    lfu_cache.put(4, 4);
    lfu_cache.get(1);
    lfu_cache.get(3);
    lfu_cache.get(4);
    lfu_cache.display();
}
