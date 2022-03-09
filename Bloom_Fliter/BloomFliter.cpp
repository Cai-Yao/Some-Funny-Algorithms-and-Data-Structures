#include "BloomFliter.h"

void BloomFilter::insert(const std::string &key)
{
    uint32_t h = hash_fn(key);
    const uint32_t delta = (h >> 17) | (h << 15);
    for (size_t i = 0; i < K; i++) {
        filter.set(h % M);
        h += delta; 
    }
    // printf("insert sucessfully!!\n");
}

bool BloomFilter::contains(const std::string &key)
{
    uint32_t h = hash_fn(key);
    const uint32_t delta = (h >> 17) | (h << 15);
    for (size_t i = 0; i < K; i++) {
        if (filter.test(h % M) == 0) {
            // printf("not find!!\n");
            return 0;
        }
        h += delta;
    }
    // printf("find !!!\n");
    return 1;
}

void BloomFilter::clear()
{
    filter.reset();
    insert_count = 0;
}

