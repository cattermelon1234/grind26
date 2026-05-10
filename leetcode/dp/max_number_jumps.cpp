#include <vector>

using namespace std;
class Solution {
public:
  int maximumJumps(vector<int> &nums, int target) {
    int n = nums.size();
    std::vector<int> dp(n, -1);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (std::abs(nums[j] - nums[i]) <= target && dp[j] != -1) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
    }
    return dp[0];
  }
};
