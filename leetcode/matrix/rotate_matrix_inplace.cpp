#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  std::pair<int, int> rotated_pos(std::pair<int, int> pos, int n) {
    return {pos.second, n - pos.first - 1};
  }
  void rotate(vector<vector<int>> &matrix) {
    // row = n - cur
    // col = i
    int n = matrix.size();
    int cur = n;
    while (cur > 0) {
      for (int i = n - cur; i < cur - 1; ++i) {
        // swap
        std::pair<int, int> first = {n - cur, i};
        std::pair<int, int> second = rotated_pos(first, n);
        std::pair<int, int> third = rotated_pos(second, n);
        std::pair<int, int> fourth = rotated_pos(third, n);
        int orig_first = matrix[first.first][first.second];
        int orig_second = matrix[second.first][second.second];
        int orig_third = matrix[third.first][third.second];
        int orig_fourth = matrix[fourth.first][fourth.second];
        matrix[first.first][first.second] = orig_fourth;
        matrix[second.first][second.second] = orig_first;
        matrix[third.first][third.second] = orig_second;
        matrix[fourth.first][fourth.second] = orig_third;
      }
      cur -= 1;
    }
  }
};
