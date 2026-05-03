#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size())
      return false;
    int n = s.size();

    for (int start = 0; start < n; ++start) {
      bool works = true;

      for (int i = 0; i < n; ++i) {
        if (s[(start + i) % n] != goal[i]) {
          works = false;
          break;
        }
      }

      if (works)
        return true;
    }

    return false;
  }
};
