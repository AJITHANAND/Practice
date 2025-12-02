#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
  int capasity;
  std::list<int> lru;
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;

public:
  LRUCache(int capacity) { this->capasity = capacity; }

  int get(int key) {
    if (cache.find(key) == cache.end()) {
      return -1;
    }
    lru.erase(cache[key].second);
    lru.push_front(key);
    cache[key].second = lru.begin();
    return cache[key].first;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      lru.erase(cache[key].second);
    } else if (cache.size() == capasity) {
      int lru_key = lru.back();
      lru.pop_back();
      cache.erase(lru_key);
    }
    lru.push_front(key);
    cache[key] = {value, lru.begin()};
  }
};

int main() {
  LRUCache cache(2);

  cache.put(1, 1);
  cache.put(2, 2);
  std::cout << cache.get(1) << std::endl; // returns 1
  cache.put(3, 3);                        // evicts key 2
  std::cout << cache.get(2) << std::endl; // returns -1 (not found)
  cache.put(4, 4);                        // evicts key 1
  std::cout << cache.get(1) << std::endl; // returns -1 (not found)
  std::cout << cache.get(3) << std::endl; // returns 3
  std::cout << cache.get(4) << std::endl; // returns 4

  return 0;
}