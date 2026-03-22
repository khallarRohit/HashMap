#pragma once
#include <iostream>
#include <vector>
#include <utility>

const size_t _HASH_SIZE_LIST[] = {7, 17, 37, 79, 163, 331, 673, 1361, 2729, 5471};

template<class K, class V> 
struct HashNode{
public:
    K key;
    V value;
    HashNode* next;

    HashNode(K key, V value);
};


template<class K, class V>
class HashMap{
private:
    std::vector<std::pair<HashNode<K,V>*, HashNode<K,V>*>> buckets; // hash table
    size_t element_count;
    double load_factor_cap;
    size_t hash_size_index;
    size_t element_count_cap;
    size_t get_bucket_index(const K& key, size_t current_bucket_count) const;
    void rehash();

public:
    HashMap();
    ~HashMap();
    void insert(const K& key, const V& value);
    V* find(const K& key);
    bool erase(const K& key);
    
};







