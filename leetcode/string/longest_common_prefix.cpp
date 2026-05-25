#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    std::unordered_set<std::string> prefixes;
    int result = 0;
    for (auto el : arr1) {
      std::string prefix = "";
      for (char c : std::to_string(el)) {
        prefix += c;
        prefixes.insert(prefix);
      }
    }
    for (auto el : arr2) {
      std::string prefix = "";
      for (char c : std::to_string(el)) {
        prefix += c;
        if (prefixes.find(prefix) != prefixes.end()) {
          result = std::max(result, (int)prefix.length());
        }
      }
    }
    return result;
  }
};
