#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <bitset>
#include <memory>

class BloomFilter
{   
private:
    static const size_t M = 10000000;
    static const size_t N = 100000;
    size_t K;
    size_t insert_count;
    std::hash<std::string> hash_fn;
    std::bitset<M> filter;
public:
    BloomFilter() : insert_count(0)
    {
        K = static_cast<size_t>(1.0 * M / N) * 0.69;
        if (K < 1) K = 1;
        if (K > 30) K = 30;
    }
    void insert(const std::string &key);
    bool contains(const std::string &key);
    void clear();
};  

#endif