#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 0; i < n + 1; ++i) {
      for (int j = 0; j < m + 1; ++j) {
        if (i == 0 || j == 0) {
          dp[i][j] = std::max(i, j);
        } else {
          dp[i][j] =
              std::min({dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]),
                        dp[i][j - 1] + 1, dp[i - 1][j] + 1});
        }
      }
    }
    return dp[n][m];
  }
};
