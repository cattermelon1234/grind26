#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    std::unordered_set<int> rows;
    std::unordered_set<int> cols;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      bool row_true = false;
      for (int j = 0; j < n; ++j) {
        if (row_true) {
          matrix[i][j] = 0;
        } else if (rows.find(i) != rows.end()) {
          matrix[i][j] = 0;
          row_true = true;
        } else if (cols.find(j) != cols.end()) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
