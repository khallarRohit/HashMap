#include <iostream>
#include <string>
#include <cassert>
#include "hashMap.h"

void test_int_int_map() {
    std::cout << "--- Testing HashMap<int, int> ---\n";
    HashMap<int, int> map;

    // 1. Test basic insertion and find
    map.insert(1, 100);
    map.insert(2, 200);
    map.insert(3, 300);

    int* val1 = map.find(1);
    assert(val1 != nullptr && *val1 == 100);
    std::cout << "[Pass] Basic insertion and find.\n";

    // 2. Test updating an existing key
    map.insert(2, 250);
    int* val2 = map.find(2);
    assert(val2 != nullptr && *val2 == 250);
    std::cout << "[Pass] Update existing key.\n";

    // 3. Test find on non-existent key
    int* val_missing = map.find(99);
    assert(val_missing == nullptr);
    std::cout << "[Pass] Find non-existent key.\n";

    // 4. Test erase
    size_t erased = map.erase(3);
    assert(erased == 1);
    assert(map.find(3) == nullptr);
    
    size_t erased_missing = map.erase(99);
    assert(erased_missing == 0);
    std::cout << "[Pass] Erase existing and non-existent keys.\n";

    // 5. Force a rehash 
    // Initial size is 7, load factor is 0.75. Cap is 5.
    // We currently have 2 elements (keys 1 and 2). Let's add 5 more to trigger rehash.
    for (int i = 10; i < 15; ++i) {
        map.insert(i, i * 10);
    }
    
    // Verify older elements survived the rehash
    assert(*map.find(1) == 100);
    assert(*map.find(14) == 140);
    std::cout << "[Pass] Rehash triggered and data preserved.\n";
}

void test_int_string_map() {
    std::cout << "\n--- Testing HashMap<int, std::string> ---\n";
    HashMap<int, std::string> map;

    map.insert(1, "Apple");
    map.insert(2, "Banana");
    map.insert(3, "Cherry");

    std::string* val = map.find(2);
    assert(val != nullptr && *val == "Banana");
    std::cout << "[Pass] String insertion and find.\n";

    map.erase(2);
    assert(map.find(2) == nullptr);
    std::cout << "[Pass] String erase.\n";
}

int main() {
    test_int_int_map();
    test_int_string_map();

    std::cout << "\nAll tests passed successfully!\n";
    return 0;
}