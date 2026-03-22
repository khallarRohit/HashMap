#include "hashMap.h"

template<class K, class V>
HashNode<K,V>::HashNode(K key, V value)
: key(key), value(value), next(nullptr){};


template<class K, class V>
size_t HashMap<K,V>::HashMap::get_bucket_index(const K& key, size_t current_bucket_count) const{
    return std::hash<K>(key) % current_bucket_count;
}

template<class K, class V>
HashMap<K,V>::HashMap()
:element_count(0), load_factor_cap(0.75f), hash_size_index(0){
    element_count_cap = load_factor_cap * _HASH_SIZE_LIST[hash_size_index];
    buckets.resize(_HASH_SIZE_LIST[hash_size_index], {nullptr, nullptr});
}

template<class K, class V>
HashMap<K,V>::~HashMap(){
    for(HashNode<K,V>* head : buckets){
        HashNode<K,V>* curr = head;
        while(curr != nullptr){
            HashNode<K,V>* prev = curr;
            curr = curr->next;
            delete prev;
        }
    }
}

template<class K, class V>
void HashMap<K,V>::rehash(){
    hash_size_index++;
    if(hash_size_index >= _HASH_SIZE_LIST.size()){
        return;
    }

    size_t new_size = _HASH_SIZE_LIST[hash_size_index];
    std::vector<std::pair<HashNode<K,V>*, HashNode<K,V>*>> new_bucket(new_size, {nullptr, nullptr});

    for(std::pair<HashNode<K,V>*, HashNode<K,V>*> bucket : buckets){
        HashNode<K,V>* head = bucket.first;
        while(head != nullptr){
            size_t new_idx = get_bucket_index(head->key, new_size);
            if(new_bucket[new_idx].second == nullptr){
                new_bucket[new_idx].first = new HashNode<K,V>(head->key, head->value);
                new_bucket[new_idx].second = new_bucket[new_idx].first;
            }else{
                HeadNode<K,V>* new_node = new Hash_Node<K,V>(head->key, head->value);
                new_bucket[new_idx].second->next = new_node;
                new_bucket[new_idx].second = new_node;
            }
        }
    }

    bucket = new_bucket;
}   

template<class K, class V>
void HashMap<K,V>::insert(const K& key, const V& value){
    if(element_count > element_count_cap){
        rehash();
    }

    size_t idx = get_bucket_index(key, _HASH_SIZE_LIST[hash_size_index]);

    for(std::pair<HashMap<K,V>*, HashMap<K,V>*> bucket : buckets){
        HashNode<K,V>* head = bucket.first;
        while(head != nullptr){
            if(head->key == key){
                head->value = value;
                return;
            }
        }
    }

    const new_node = new HashNode<K,V>(key, value);
    bucket[idx].second->next = new_node;
    bucket[idx].second = new_node;
    element_count++;
}

template<class K, class V>
V* HashMap<K,V>::find(const K& key){
    size_t idx = get_bucket_index(key, _HASH_SIZE_LIST[hash_size_index]);
    
    HashNode<K,V>* head = buckets[idx].first;
    while(head != nullptr){
        if(head->key == key){
            return &head->value
        }
    }
    return nullptr;
}

template<class K, class V>
bool HashMap<K,V>::erase(const K& key){
    size_t idx = get_bucket_index(key, _HASH_SIZE_LIST[hash_size_index]);
    
    HashNode<K,V>* head = buckets[idx].first;
    HashNode<K,V>* prev = nullptr;

    


}


int main(){


    return 0;
}






