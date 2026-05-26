#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
  int numberOfSpecialChars(string word) {
    std::unordered_set<char> seen;
    std::unordered_set<char> special;
    for (int i = 0; i < word.size(); ++i) {
      if (std::islower(static_cast<unsigned char>(word[i]))) {
        if (seen.find(std::toupper(word[i])) != seen.end()) {
          special.insert(std::tolower(word[i]));
        }
      } else {
        if (seen.find(std::tolower(word[i])) != seen.end()) {
          special.insert(std::tolower(word[i]));
        }
      }
      seen.insert(word[i]);
    }
    return special.size();
  }
};
