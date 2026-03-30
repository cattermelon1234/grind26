#include <list>
#include <unordered_map>
#include <vector>

/* PROBLEM SUMMARY
 * literally just LRU cache, never did this before in c++ though.
 *
 *
 * NOTES:
 * slightly tricky because we have to use iterators to keep track of the cache
 * items. Design is a little hard to think of at first, but eventually I settled
 * on a std::list of pairs and a map key->iterator. We need to store pairs in
 * the std::list because when we evict an item, we need to know the key to
 * remove it from the map. If we only stored values, this would not be possible.
 * And we need to store an iterator instead of just a value in the map because
 * we moving around in std::list uses splice, which takes in an iterator
 * pointing to an element in the list.
 */

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
