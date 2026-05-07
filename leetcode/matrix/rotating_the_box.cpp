#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid) {
    int m = boxGrid.size();
    int n = boxGrid[0].size();

    vector<vector<char>> rotatedGrid(n, vector<char>(m, '.'));

    for (int i = 0; i < m; ++i) {
      int write = n - 1; // lowest available spot in this rotated column

      for (int j = n - 1; j >= 0; --j) {
        int col = m - i - 1;

        if (boxGrid[i][j] == '*') {
          rotatedGrid[j][col] = '*';
          write = j - 1; // stones above this obstacle land above it
        } else if (boxGrid[i][j] == '#') {
          rotatedGrid[write][col] = '#';
          write--;
        }
      }
    }

    return rotatedGrid;
  }
};
