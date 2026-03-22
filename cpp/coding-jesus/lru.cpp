#include <list>
#include <vector>
#include <list>
#include <unordered_map>

class LRUCache {
private:
    // TODO: Define data structures to store cache items and their order
    // Hint: A combination of std::list and std::unordered_map is efficient
    std::list<std::pair<int, int>> lru;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
    int cap = 0;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        // TODO: Return value or -1 if not found
        if (map.find(key) == map.end()) {
            return -1;
        }
        // move element to first
        auto it = map[key];
        lru.splice(lru.begin(), lru, it);
        // return element
        return it->second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            auto it = map[key];
            it->second = value;
            lru.splice(lru.begin(), lru, it);
        }
        else if (lru.size() >= cap) {
            auto evicted = lru.back();
            map.erase(evicted.first);
            lru.pop_back();
        }
        lru.emplace_front(key, value);
        map[key] = lru.begin();
    }
};
#include <unordered_map>
#include <vector>

class LRUCache {
private:
  // TODO: Define data structures to store cache items and their order
  // Hint: A combination of std::list and std::unordered_map is efficient
  std::list<std::pair<int, int>> lru;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
  int cap = 0;

public:
  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    // TODO: Return value or -1 if not found
    if (map.find(key) == map.end()) {
      return -1;
    }
    // move element to first
    auto it = map[key];
    lru.splice(lru.begin(), lru, it);
    // return element
    return it->second;
  }

  void put(int key, int value) {
    if (map.find(key) != map.end()) {
      auto it = map[key];
      it->second = value;
      lru.splice(lru.begin(), lru, it);
    } else if (lru.size() >= cap) {
      auto evicted = lru.back();
      map.erase(evicted.first);
      lru.pop_back();
    }
    lru.emplace_front(key, value);
    map[key] = lru.begin();
  }
};
